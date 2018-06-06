using System;
using System.Collections.Generic;
using System.Text;


public abstract class IVehicle
{
    private double fuelAmount;
    private double fuelConsumption;
    private double airConditioningConsumption;
    private double tankCapacity;

    public IVehicle(double fuelAmount, double fuelConsumption, double airConditioningConsumption, double tankCapacity)
    {
        this.fuelAmount = fuelAmount;
        this.FuelConsumption = fuelConsumption;
        this.airConditioningConsumption = airConditioningConsumption;
        this.TankCapacity = tankCapacity;
    }

    public double TankCapacity { get => tankCapacity; set => tankCapacity = value; }
    public double FuelConsumption { get => fuelConsumption; set => fuelConsumption = value; }

    protected virtual double FuelAmount
    {
        get
        {
            return this.FuelAmount;
        }

        set
        {
            if (value <= 0)
            {
                throw new ArgumentException("Fuel must be a positive number");
            }

            this.fuelAmount = value;
        }
    }

    public virtual string Driving(double distance)
    {
        var neededFuel = (this.FuelConsumption + this.airConditioningConsumption) * distance;

        if (neededFuel>this.fuelAmount)
        {
            return $"{this.GetType().Name} needs refueling";
        }
        else
        {
            this.fuelAmount -= neededFuel;
            return $"{this.GetType().Name} travelled {distance} km";
            
        }

    }
    public virtual void Refuel(double fuel)
    {
        if (fuel <= 0)
        {
            throw new ArgumentException("Fuel must be a positive number");
        }
        else
        {
            this.fuelAmount += fuel;
        }

        
    }
    public override string ToString()
    {
        return $"{this.GetType().Name}: {this.fuelAmount:F2}";
    }
}

