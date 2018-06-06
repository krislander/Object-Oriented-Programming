using System;
using System.Collections.Generic;
using System.Text;


public class Truck : IVehicle
{
    private const double TakenFuelInCharging = 0.95;

    public Truck(double fuelAmount, double fuelConsumption, double airConditioningConsumption, double tankCapacity) 
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

    public override void Refuel(double fuel)
    {
        fuel *= TakenFuelInCharging;
        base.Refuel(fuel);
    }
}
