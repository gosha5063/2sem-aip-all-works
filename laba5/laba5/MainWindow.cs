using System;
using Gtk;

public partial class MainWindow: Gtk.Window
{
	public MainWindow () : base (Gtk.WindowType.Toplevel)
	{
		Build ();
	}

	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}
	class Program{
		private string[]s;
		public Program(string[] s_i){
			s = s_i;
		}
		public void smth(MainWindow m){
			int n = this.s	.Length;
			for (int i = 0; i < n; i++)
			{
				int groups = 0;
				int count = 0;
				foreach (char item in s[i])
				{
					if(char.IsLetter(item)){
						count++;
					}
					else{
						if(count!=0){
							groups++;
						}
						count = 0;
					}
				}
				if(groups>1){
					s[i] = s[i].Replace('+','1');
					s[i] = s[i].Replace('-','2');
					s[i] = s[i].Replace('*','3');
				}
			}
			for (int i = 0; i < n; i++)
			{
				m.textview2.Buffer.Text += (s[i])+'\n';
			}

		}
	}
	protected void OnButton1Clicked (object sender, EventArgs e)
	{
		string[] s = this.textview1.Buffer.Text.Split('\n');
		Program p = new Program(s);
		p.smth(this);
	}
}
