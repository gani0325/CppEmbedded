using MQTTnet;
using MQTTnet.Client.Receiving;
using MQTTnet.Protocol;
using MQTTnet.Server;
using System;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace MqttServerTest
{
    class Program
    {
        private static MqttServer mqttServer = null;
        static void Main(string[] args)
        {
            new Thread(StartMqttServer).Start();
            while (true)
            {
                string inputString = Console.ReadLine()?.ToLower().Trim();
                if (inputString == "exist")
                {
                    mqttServer?.StopAsync();
                    Console.WriteLine("Server Down!");
                    break;
                }
                else if (inputString == "clients")
                {
                    foreach (var item in mqttServer.GetClientStatusAsync().Result)
                    {
                        Console.WriteLine($"Client: {item.ClientId},Protocal: {item.ProtocolVersion}");
                    }
                }
                else
                {
                    Console.WriteLine("cmd not exist!");
                }
            }
        }

        private static void StartMqttServer()
        {
            if (mqttServer == null)
            {
                try
                {
                    //
                    var options = new MqttServerOptionsBuilder()
                    .WithConnectionValidator((context) =>
                    {
                        if (string.IsNullOrEmpty(context.ClientId))
                        {
                            if (context.ClientId == "c001")
                            {
                                if (context.Username != "u001" || context.Password != "p002")
                                {
                                    context.ReasonCode = MqttConnectReasonCode.BadUserNameOrPassword;
                                    Console.WriteLine("Error");
                                }
                            }
                            //context.AssignedClientIdentifier = "test123";
                            //context.ReasonCode = MqttConnectReasonCode.Success;
                        }
                    });

                    //Create mqtt server
                    mqttServer = new MqttFactory().CreateMqttServer() as MqttServer;

                    //ReceivedHandler 
                    mqttServer.ApplicationMessageReceivedHandler = new MqttApplicationMessageReceivedHandlerDelegate(async c =>
                    {
                        await mqttServer.SubscribeAsync(c.ClientId, "topic1");
                        Console.WriteLine($"action {c.ClientId} {Encoding.UTF8.GetString(c.ApplicationMessage.Payload)}");
                    });

                    //
                    mqttServer.ClientConnectedHandler = new MqttServerClientConnectedHandlerDelegate(c =>
                    {
                        Console.WriteLine($"connected {c.ClientId}");
                    });

                    //
                    mqttServer.ClientDisconnectedHandler = new MqttServerClientDisconnectedHandlerDelegate(c =>
                    {
                        Console.WriteLine($"disconnected {c.ClientId}");
                    });
                    mqttServer.StartAsync(options.Build());
                    Console.WriteLine("MQTT 서비스가 성공적으로 시작되었습니다.！");

                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                    return;
                }
            }
        }
    }
}