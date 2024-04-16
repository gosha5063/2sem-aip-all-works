using System;
using Gtk;

public partial class MainWindow: Gtk.Window
{
	String curSign;
	int moveNum;
	bool gameEnded;
	public MainWindow () : base (Gtk.WindowType.Toplevel)
	{
		Build ();
		curSign = "X";
		moveNum = 1;
		gameEnded = false;
	}

	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}
		
	protected void OnButton1Clicked (object sender, EventArgs e)
	{
		curSign = "X";
		moveNum = 1;
		gameEnded = false;
		this.button2.Label = "";
		this.button3.Label = "";
		this.button4.Label = "";
		this.button5.Label = "";
		this.button6.Label = "";
		this.button7.Label = "";
		this.button8.Label = "";
		this.button9.Label = "";
		this.button10.Label = "";
		this.results.Text = "Игра началась!";
	}
	private void clicked(object sender, EventArgs e){
		Button button = (Button) sender;
		if (string.IsNullOrEmpty (button.Label) & !gameEnded) {
			button.Label = curSign;
			if (!string.IsNullOrEmpty (this.button2.Label)
				& this.button2.Label == this.button3.Label
				& this.button3.Label == this.button4.Label
			|
			!string.IsNullOrEmpty (this.button5.Label)
			& this.button5.Label == this.button6.Label
			& this.button6.Label == this.button7.Label
			|
			!string.IsNullOrEmpty (this.button8.Label)
			& this.button8.Label == this.button9.Label
			& this.button9.Label == this.button10.Label
			|

			!string.IsNullOrEmpty (this.button2.Label)
			& this.button1.Label == this.button5.Label
			& this.button5.Label == this.button8.Label
			|
			!string.IsNullOrEmpty (this.button2.Label)
			& this.button2.Label == this.button5.Label
			& this.button5.Label == this.button8.Label
			|
			!string.IsNullOrEmpty (this.button3.Label)
			& this.button3.Label == this.button6.Label
			& this.button6.Label == this.button9.Label
			|
			!string.IsNullOrEmpty (this.button4.Label)
			& this.button4.Label == this.button7.Label
			& this.button7.Label == this.button10.Label
			|
			!string.IsNullOrEmpty (this.button2.Label)
			& this.button2.Label == this.button6.Label
			& this.button6.Label == this.button10.Label
			|
			!string.IsNullOrEmpty (this.button4.Label)
			& this.button4.Label == this.button6.Label
			& this.button6.Label == this.button8.Label
			) {
				gameEnded = true;
				this.results.Text = "Ход " + moveNum.ToString() +
					": Победил " + curSign + "!";
			}
			else if (!string.IsNullOrEmpty (this.button1.Label) &
				!string.IsNullOrEmpty (this.button2.Label) &
				!string.IsNullOrEmpty (this.button3.Label) &
				!string.IsNullOrEmpty (this.button4.Label) &
				!string.IsNullOrEmpty (this.button5.Label) &
				!string.IsNullOrEmpty (this.button6.Label) &
				!string.IsNullOrEmpty (this.button7.Label) &
				!string.IsNullOrEmpty (this.button8.Label) &
				!string.IsNullOrEmpty (this.button9.Label)
			) {
				gameEnded = true;
				this.results.Text = "Ход " + moveNum.ToString() +
					": Ничья!";
			}
			else
				this.results.Text = "Ход " + moveNum.ToString() +
					": " + curSign + " сходил на " +
					button.Name[6] + " клетку";
			if (curSign == "X")
				curSign = "O";
			else
				curSign = "X";
			moveNum += 1;
		}
	}


}
