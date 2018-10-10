using System;
using System.Collections.Generic;
using System.Text;

namespace Exercise1.Library
{
    class BluRay : Item,IDownloadable
    {
        private List<Track> tracks;

        public BluRay(List<Track> Tracks)
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
