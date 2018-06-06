using System;
using System.Collections.Generic;
using System.Text;


public class Bus : IVehicle
{
    private bool isACon;

    public Bus(double fuelAmount, double fuelConsumption, double airConditioningConsumption, double tankCapacity) 
        : base(fuelAmount, fuelConsumption, airConditioningConsumption, tankCapacity)
    {
        this.IsACon = true;
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

    public bool IsACon
    {
        get { return this.IsACon; }
        set { this.IsACon = value; }
    }

    public override string Driving(double distance)
    {
        if (this.IsACon)
        {
            return base.Driving(distance);
        }
        var neededFuel = this.FuelConsumption * distance;

        if (neededFuel > this.FuelAmount)
        {
            return $"Bus needs refueling";
        }

        this.FuelAmount -= neededFuel;
        return $"Bus travelled {distance} km";
    }
}

