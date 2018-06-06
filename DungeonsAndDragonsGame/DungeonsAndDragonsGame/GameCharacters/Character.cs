using System;
using System.Collections.Generic;
using System.Text;


public abstract class Character
{
    private string name;
    private double baseHealth;
    private double health;
    private double baseArmor;
    private double armor;
    private double abilityPoints;
    private Bag bag;
    private Faction faction;
    private bool isAlive;

    internal void DecreaseHealth(int points)
    {
        this.Health = Math.Max(0, this.Health - points);

        if (this.Health <=0)
        {
            this.IsAlive = false;
        }
    }

    internal void RestoreArmor()
    {
        this.Armor = this.BaseArmor;
    }


    public Character(string name, double health, double armor, double abilityPoints, Bag bag, Faction faction)
    {
        this.name = name;
        this.baseHealth = health;
        this.health = health;
        this.baseArmor = armor;
        this.armor = armor;
        this.abilityPoints = abilityPoints;
        this.bag = bag;
        this.faction = faction;
        this.isAlive = true;
    }

    public string Name
    {
        get { return this.name; }
        private set
        {
            if (String.IsNullOrEmpty(value) || String.IsNullOrWhiteSpace(value))
            {
                throw new ArgumentException($"Name cannot be null or whitespace");
            }
        }
    }
    public virtual double RestHealMultiplier
    {
        get { return 0.2; }
    }

    public bool IsAlive
    {
        get { return isAlive; }
        private set { isAlive = value; }
    }

    public Faction Faction
    {
        get { return faction; }
        private set { faction = value; }
    }

    public Bag Bag
    {
        get { return bag; }
        private set { bag = value; }
    }

    public double AbilityPoints
    {
        get { return abilityPoints; }
        private set { abilityPoints = value; }
    }

    public double Armor
    {
        get { return armor; }
        private set { armor = value; }
    }

    public double BaseArmor
    {
        get { return baseArmor; }
        private set { baseArmor = value; }
    }

    public double Health
    {
        get { return health; }
        private set { health = value; }
    }

    public double BaseHealth
    {
        get { return baseHealth; }
        private set { baseHealth = value; }
    }

    public void TakeDamage(double hitPoints)
    {
        this.CheckIfAlive();

        if (this.Armor<hitPoints)
        {
            hitPoints -= Armor;
            this.Armor = 0;
            Health -= hitPoints;

            if (Health <= 0)
            {
                this.IsAlive = false;
                this.Health = 0;
            }

            return;
        }
        this.Armor -= hitPoints;
    }

    public void Rest()
    {
        this.CheckIfAlive();

        this.Health = this.Health + (this.BaseHealth * this.RestHealMultiplier);

        if (this.Health > this.BaseHealth)
        {
            this.Health = this.BaseHealth;
        }
    }

    public void UseItem(Item item)
    {
        this.CheckIfAlive();

        item.AffectCharacter(this);
    }

    public void UseItemOn(Item item, Character character)
    {
        this.CheckIfAlive();
        //check if other character is alive
        character.CheckIfAlive();

        item.AffectCharacter(character);
    }

    public void GiveCharacterItem(Item item, Character character)
    {
        this.CheckIfAlive();
        //check if other character is alive
        character.CheckIfAlive();

        character.ReceiveItem(item);
    }

    public void ReceiveItem(Item item)
    {
        this.CheckIfAlive();

        this.Bag.AddItem(item);
    }

    internal void IncreaseHealth(double points)
    {
        this.Health = this.Health + points;

        if (this.Health > this.BaseHealth)
            this.Health = this.BaseHealth;
    }

    internal void CheckIfAlive()
    {
        if (!this.IsAlive)
        {
            throw new InvalidOperationException("Must be alive to perform this action!");
        }
    }
}

