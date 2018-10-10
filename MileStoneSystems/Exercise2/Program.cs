using System;
using System.Collections.Generic;
using System.Linq;

namespace Exercise2
{
    class Program
    {
        static void Main(string[] args)
        {
            Book bookOne = new Book(new List<string>() {"Brian Jensen"}, "Texts from Denmark", "Gyldendal", 2001);
            Book bookTwo = new Book(new List<string>() { "Peter Jensen", "Hans Andersen" }, "Stories from abroad", "Borgen", 2012);
            Book bookThree= new Book();
            List<Book> books = new List<Book>() { bookOne, bookTwo};

            Console.WriteLine("Enter the book information in this order: Authors, Title, Publisher, Year of publish: ");
            string[] input = Console.ReadLine().Split(new string[] { ","},StringSplitOptions.RemoveEmptyEntries).ToArray();
            bookThree.ReadBooks(input, books);

            Console.WriteLine("Enter the keywords you want to search by: ");
            string[] searchstring = Console.ReadLine().Split(new string[] { "," }, StringSplitOptions.RemoveEmptyEntries).ToArray();
            FindBooks(searchstring, books);
        }

        static List<Book> FindBooks(string[] searchString, List<Book> books)
        {
            List<Book> result = new List<Book>();

            foreach (var book in books)
            {
                for (int i = 0; i < searchString.Length; i++)
                {
                    if (book.Authors.ToString() == searchString[i] ||
                        book.Title == searchString[i] ||
                        book.Publisher == searchString[i] ||
                        book.PublicationYear.ToString() == searchString[i])
                    {
                        //we add every time we find a match
                        result.Add(book);
                    }
                }
            }
            //now remove duplicates
            return result.Distinct().ToList();

            //its not optimal 
        }
    }
}
