using System;
using Gtk;

namespace my_first_project
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Application.Init ();
			MainWindow win = new MainWindow ();

			win.Show ();
			Application.Run ();
		}
	}
}
