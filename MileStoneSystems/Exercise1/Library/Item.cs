using System;
using System.Collections.Generic;
using System.Text;

namespace Exercise1.Library
{
    public abstract class Item
    {
        private string title;
        private string isbn;

        //public Item(string Title, string ISBN)
        //{
        //    this.title = Title;
        //    this.isbn = ISBN;
        //}

        public string Title
        {
            get { return title; }
            set { title = value; }
        }
        public string ISBN
        {
            get { return isbn; }
            set { isbn = value; }
        }

        private static bool IsValidISBN(string ISBN)
        {
            // length must be 10 
            int n = ISBN.Length;
            if (n != 10)
                return false;

            // Computing weighted sum  
            // of first 9 digits 
            int sum = 0;
            for (int i = 0; i < 9; i++)
            {
                int digit = ISBN[i] - '0';
                if (0 > digit || 9 < digit)
                    return false;
                sum += (digit * (10 - i));
            }

            // Checking last digit. 
            char last = ISBN[9];
            if (last != 'X' && (last < '0' ||
                                last > '9'))
                return false;

            // If last digit is 'X', add 10  
            // to sum, else add its value. 
            sum += ((last == 'X') ? 10 :
                          (last - '0'));

            // Return true if weighted sum  
            // of digits is divisible by 11. 
            return (sum % 11 == 0);
        }
    }
}
