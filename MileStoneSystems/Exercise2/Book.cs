using System;
using System.Collections.Generic;
using System.Text;

namespace Exercise2
{
    class Book
    {
        private List<string> authors;
        private string title;
        private string publisher;
        private int publicationYear;

        public Book()
        {
            this.authors = new List<string>();
            this.title = "";
            this.publisher = "";
            this.publicationYear = 0;
        }

        public Book(List<string> Authors, string Title, string Publisher, int PublicationYear)
        {
            Authors = authors;
            Title = title;
            Publisher = publisher;
            PublicationYear = publicationYear;
        }

        public int PublicationYear
        {
            get { return publicationYear; }
            set { publicationYear = value; }
        }

        public string Publisher
        {
            get { return publisher; }
            set { publisher = value; }
        }

        public string Title
        {
            get { return title; }
            set { title = value; }
        }

        public List<string> Authors
        {
            get { return authors; }
            set { authors = value; }
        }

        public List<Book> ReadBooks(string[] input, List<Book> books)
        {
            //tova e za vavejdane na edna kniga
            Book book = new Book();

            book.PublicationYear = int.Parse(input[input.Length - 1]);
            book.Publisher = input[input.Length - 2];
            book.Title = input[input.Length - 3];
            for (int i = 0; i < input.Length - 3; i++)
            {
                //dobavqne na vseki avtor
                book.Authors.Add(input[i]);
            }

            //printirane
            var sb = new StringBuilder();
            sb.AppendLine($"The book is titled {book.Title} and it is written by: ");
            foreach (var author in book.Authors)
            {
                sb.Append(author + " ");
            }
         
            sb.AppendLine();
            sb.AppendLine($"Published by {book.Publisher} in the year {book.PublicationYear}.");

            books.Add(book);
            Console.WriteLine(sb);

            //return-va nov List s dobavenata kniga
            return books;
        }
    }
}
