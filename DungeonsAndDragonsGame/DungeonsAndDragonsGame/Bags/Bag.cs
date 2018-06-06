using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public abstract class Bag
{
    private int capacity;
    private List<Item> items;

    public Bag(int capacity = 100)
    {
        this.capacity = capacity;
        this.items = new List<Item>();
    }

    public IReadOnlyCollection<Item> Items
    {
        get { return items; }
    }

    public int Capacity
    {
        get {return this.capacity; }
        private set { capacity = value; }
    }

    public int Load { get { return this.items.Sum(x => x.Weight); } }

    public void AddItem(Item item)
    {
        if (Load + item.Weight > this.Capacity)
        {
            throw new InvalidOperationException("Bag is empty");
            
        }
        this.items.Add(item);
    }
    public Item GetItem(string name)
    {
        if (Items.Count == 0)
        {
            throw new InvalidOperationException("Bag is empty");
        }

        var item = this.Items.FirstOrDefault(x => x.GetType().Name == name);

        if (item == null)
            throw new ArgumentException($"No item with name {name} in bag!");

        this.items.Remove(item);

        return item;
    }
}

