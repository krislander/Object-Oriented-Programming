using System;
using System.Collections.Generic;
using System.Text;


public class Car : IVehicle
{
    public Car(double fuelAmount, double fuelConsumption, double airConditioningConsumption, double tankCapacity) 
        : base(fuelAmount, fuelConsumption, airConditioningConsumption, tankCapacity)
    {
    }

    protected override double FuelAmount
    {
        set
        {
            if (value > this.TankCapacity)
            {
                throw new ArgumentException("Cannot fit fuel in tank");
            }
            base.FuelAmount = value;
        }
    }
}

