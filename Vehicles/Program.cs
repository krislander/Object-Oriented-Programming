using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    private const double CarAirCondConsumption = 0.9;
    private const double TruckAirCondConsumption = 1.6;
    private const double BusAirCondConsumption = 1.4;

    static void Main(string[] args)
    {
        var CarData = Console.ReadLine().Split();
        var car = new Car(double.Parse(CarData[1]), double.Parse(CarData[2]), CarAirCondConsumption, double.Parse(CarData[3]));
        var TruckData = Console.ReadLine().Split();
        var truck = new Truck(double.Parse(TruckData[1]), double.Parse(TruckData[2]), TruckAirCondConsumption, double.Parse(CarData[3]));
        var BusData = Console.ReadLine().Split();
        var bus = new Bus(double.Parse(TruckData[1]), double.Parse(TruckData[2]), TruckAirCondConsumption, double.Parse(CarData[3]));

        int numberOfCommands = int.Parse(Console.ReadLine());

        while (numberOfCommands > 0)
        {
            var command = Console.ReadLine().Split();
            var action = command[0];
            var vehicleType = command[1];
            var vehicleData = double.Parse(command[2]);


            try
            {
                switch (action)
                {
                    case "Drive":
                        if (vehicleType == "car")
                            car.Driving(vehicleData);
                        else
                            truck.Driving(vehicleData);
                        break;
                    case "Refuel":
                        if (vehicleType == "truck")
                            truck.Refuel(vehicleData);
                        else
                            car.Refuel(vehicleData);
                        break;
                    case "DriveEmpty":
                        bus.Driving(vehicleData);
                        break;
                    default:
                        break;
                }

                numberOfCommands--;

                Console.WriteLine(car);
                Console.WriteLine(truck);
                Console.WriteLine(bus);
            }
            catch (ArgumentException ae)
            {
                Console.WriteLine(ae.Message);
            }
        } 
    }
}

