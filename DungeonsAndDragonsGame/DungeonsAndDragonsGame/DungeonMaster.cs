using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class DungeonMaster
{
    private Dictionary<string, Character> characters = new Dictionary<string, Character>();
    Stack<Item> itemPool = new Stack<Item>();
    int rounds = 0;

    public string JoinParty(string[] args)
    {
        object factionParse;
        if (!Enum.TryParse(typeof(Faction), args[0], out factionParse))
        {
            throw new ArgumentException($"Invalid faction \"{args[0]}\"!");
        }

        Faction faction = (Faction)factionParse;

        if (args[1] != nameof(Cleric) && args[1] != nameof(Warrior))
        {
            throw new ArgumentException($"Invalid character type \"{ args[1] }\"!");
        }

        Character temp = null;

        switch (args[1])
        {
            case nameof(Warrior):
                temp = new Warrior(args[2], faction);
                break;
            case nameof(Cleric):
                temp = new Cleric(args[2], faction);
                break;
        }
        characters.Add(temp.Name, temp);

        return ($"{temp.Name} joined the party!");
    }

    public string AddItemToPool(string[] args)
    {
        if (args[0] != nameof(ArmorRepairKit) && args[0] != nameof(PoisonPotion) && args[0] != nameof(HealthPotion))
        {
            throw new ArgumentException($"Invalid item \"{args[0]}\"!");
        }

        Item temp = null;

        switch (args[0])
        {
            case nameof(ArmorRepairKit):
                temp = new ArmorRepairKit();
                break;
            case nameof(PoisonPotion):
                temp = new PoisonPotion();
                break;
            case nameof(HealthPotion):
                temp = new HealthPotion();
                break;
        }

        itemPool.Push(temp);
        return $"{args[0]} added to pool!";
    }

    public string PickUpItem(string[] args)
    {
        if (!characters.ContainsKey(args[0]))
        {
            throw new ArgumentException($"Character {args[0]} not found!");
        }
        if (itemPool.Count == 0)
        {
            throw new InvalidOperationException($"No items left in the pool!");
        }

        var character = characters[args[0]];
        var item = itemPool.Pop();
        character.ReceiveItem(item);

        return $"{character.Name} picked up {item.GetType().Name}!";
    }

    public string UseItem(string[] args)
    {
        if (!characters.ContainsKey(args[0]))
        {
            throw new ArgumentException($"Character {args[0]} not found!");
        }
        var character = characters[args[0]];
        var item = character.Bag.GetItem(args[1]);
        character.UseItem(item);

        return $"{character.Name} used {item.GetType().Name}.";
    }

    public string UseItemOn(string[] args)
    {
        if (!characters.ContainsKey(args[0]))
        {
            throw new ArgumentException($"Character {args[0]} not found!");
        }

        if (!characters.ContainsKey(args[1]))
        {
            throw new ArgumentException($"Character {args[1]} not found!");
        }

        var giver = characters[args[0]];
        var receiver = characters[args[1]];
        var item = giver.Bag.GetItem(args[2]);

        giver.UseItemOn(item, receiver);

        return $"{giver.Name} used {item.GetType().Name} on {receiver.Name}.";
    }

    public string GiveCharacterItem(string[] args)
    {
        if (!characters.ContainsKey(args[0]))
        {
            throw new ArgumentException($"Character {args[0]} not found!");
        }

        if (!characters.ContainsKey(args[1]))
        {
            throw new ArgumentException($"Character {args[1]} not found!");
        }

        var giver = characters[args[0]];
        var receiver = characters[args[1]];
        var item = giver.Bag.GetItem(args[2]);

        giver.GiveCharacterItem(item, receiver);

        return $"{giver.Name} gave {receiver.Name} {item.GetType().Name}.";
    }

    public string GetStats()
    {
        var printer = new StringBuilder();

        foreach (var entity in characters.Values.OrderByDescending(x => x.IsAlive).ThenByDescending(y => y.Health))
        {
            printer.AppendLine($"{entity.Name} - HP: {entity.Health}/{entity.BaseHealth}, AP: {entity.Armor}/{entity.BaseArmor}, Status: {(entity.IsAlive ? "Alive" : "Dead")}");
        }
        return printer.ToString().TrimEnd();
    }

    public string Attack(string[] args)
    {
        if (!characters.ContainsKey(args[0]))
        {
            throw new ArgumentException($"Character {args[0]} not found!");
        }

        if (!characters.ContainsKey(args[1]))
        {
            throw new ArgumentException($"Character {args[1]} not found!");
        }

        var attacker = characters[args[0]];
        var attacked = characters[args[1]];

        if (!(attacker is IAttackable))
        {
            throw new ArgumentException($"{attacker.Name} cannot attack!");
        }

        ((IAttackable)attacker).Attack(attacked);

        var printer = new StringBuilder();

        printer.AppendLine($"{attacker.Name} attacks {attacked.Name} for {attacker.AbilityPoints} hit points!" +
            $" {attacked.Name} has {attacked.Health}/{attacked.BaseHealth} HP and {attacked.Armor}/{attacked.BaseArmor} AP left!");

        if (!attacked.IsAlive)
        {
            printer.AppendLine($"{attacked.Name} is dead!");
        }

        return printer.ToString().TrimEnd();
    }

    public string Heal(string[] args)
    {
        if (!characters.ContainsKey(args[0]))
        {
            throw new ArgumentException($"Character {args[0]} not found!");
        }

        if (!characters.ContainsKey(args[1]))
        {
            throw new ArgumentException($"Character {args[1]} not found!");
        }

        var healer = characters[args[0]];
        var healed = characters[args[1]];

        if (!(healer is IHealable))
        {
            throw new ArgumentException($"{healer.Name} cannot heal!");
        }

        ((IHealable)healer).Heal(healed);

        return $"{healer.Name} heals {healed.Name} for {healer.AbilityPoints}! {healed.Name} has {healed.Health} health now!";
    }

    public string EndTurn(string[] args)
    {
        var alive = this.characters.Values
            .Where(x => x.IsAlive).ToList();

        var printer = new StringBuilder();
        foreach (var entity in alive)
        {
            var oldHealth = entity.Health;
            entity.Rest();
            printer.AppendLine($"{entity.Name} rests ({oldHealth} => {entity.Health})");
        }
        if (alive.Count <=1)
        {
            this.rounds++;
        }

        return printer.ToString().TrimEnd();
    }

    public bool IsGameOver()
    {
        return rounds > 1;
    }

}

