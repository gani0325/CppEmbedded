using System;
interface IEatble
{
    void Eating();
}
class Apple : IEatble
{
    public void Eating()
    {
        Console.WriteLine("Apple Yammy!!");
    }
}
class Orange : IEatble
{
    public void Eating()
    {
        Console.WriteLine("Orange Yammy!!");
    }
}
interface IEater
{
    void Consume(IEatble fruit);
}
class Human : IEater
{
    public void Consume(IEatble fruit)
    {
        Console.WriteLine("The human is eating a fruit:");
        fruit.Eating();
    }
}
class Program
{
    static void Main(string[] args)
    {
        Apple ap=new Apple();
        Orange or=new Orange();
        Human hm=new Human();
        hm.Consume(ap);
        hm.Consume(or);
  
        //IEatble eat= new IEatble();
        
    }
}