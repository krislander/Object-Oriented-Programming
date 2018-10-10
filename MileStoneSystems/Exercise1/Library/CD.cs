using System;
using System.Collections.Generic;
using System.Text;

namespace Exercise1.Library
{
    class CD : Item,IDownloadable
    {
        private List<Track> tracks;

        public CD(List<Track> Tracks)
        {
            Tracks = tracks;
        }

        public List<Track> Tracks
        {
            get { return tracks; }
            set { tracks = value; }
        }

        public void IsDownloadable(Item item)
        {
            //check if it is downloadable
        }
    }
}
