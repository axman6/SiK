
// This file has been generated by the GUI designer. Do not modify.
namespace uploader
{
	public partial class Mon
	{
		private global::Gtk.ScrolledWindow scrolledwindow2;
		private global::Gtk.TextView textview2;
		
		protected virtual void Build ()
		{
			global::Stetic.Gui.Initialize (this);
			// Widget uploader.Mon
			this.Name = "uploader.Mon";
			this.Title = global::Mono.Unix.Catalog.GetString ("Mon");
			this.WindowPosition = ((global::Gtk.WindowPosition)(4));
			// Container child uploader.Mon.Gtk.Container+ContainerChild
			this.scrolledwindow2 = new global::Gtk.ScrolledWindow ();
			this.scrolledwindow2.CanFocus = true;
			this.scrolledwindow2.Name = "scrolledwindow2";
			this.scrolledwindow2.ShadowType = ((global::Gtk.ShadowType)(1));
			// Container child scrolledwindow2.Gtk.Container+ContainerChild
			this.textview2 = new global::Gtk.TextView ();
			this.textview2.CanFocus = true;
			this.textview2.Name = "textview2";
			this.textview2.Editable = false;
			this.textview2.CursorVisible = false;
			this.textview2.WrapMode = ((global::Gtk.WrapMode)(1));
			this.scrolledwindow2.Add (this.textview2);
			this.Add (this.scrolledwindow2);
			if ((this.Child != null)) {
				this.Child.ShowAll ();
			}
			this.DefaultWidth = 570;
			this.DefaultHeight = 252;
			this.Show ();
		}
	}
}