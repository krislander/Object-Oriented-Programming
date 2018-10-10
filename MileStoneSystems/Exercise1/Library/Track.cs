using System;
using System.Collections.Generic;
using System.Text;

namespace Exercise1.Library
{
    class Track
    {
        private string title;
        private string artist;
        private double duration;
        private string type;

        public Track(string title, string artist, double duration, string type)
        {
            Title = title;
            Artist = artist;
            Duration = duration;
            Type = type;
        }

        public string Type
        {
            get { return type; }
            private set
            {
                type = value;
                if (value.ToLower() != "audio" || value.ToLower() != "video")
                {
                    throw new ArgumentException($"Invalid track type!");
                }
            }
        }

        public double Duration
        {
            get { return duration; }
            set { duration = value; }
        }

        public string Artist
        {
            get { return artist; }
            set { artist = value; }
        }

        public string Title
        {
            get { return title; }
            set { title = value; }
        }
    }
}
