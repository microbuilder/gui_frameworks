package main

import (
	"log"

	"github.com/gotk3/gotk3/gtk"
)

func print_hello() {
	print("Hello, gotk3!\n")

	// Quit the application
	gtk.MainQuit()
}

func set_menu(box *gtk.Box) {
	// Menu vertical box
	vbox, _ := gtk.BoxNew(gtk.ORIENTATION_VERTICAL, 0)
	box.Container.Add(vbox)

	// Menu bar
	mb, _ := gtk.MenuBarNew()

	// File Menu
	fm, _ := gtk.MenuNew()
	fm_root, _ := gtk.MenuItemNewWithLabel("File")
	fm_quit, _ := gtk.MenuItemNewWithLabel("Quit")
	fm_root.SetSubmenu(fm)
	fm.MenuShell.Append(fm_quit)
	mb.MenuShell.Append(fm_root)

	// Connect quit handler
	fm_quit.Connect("activate", func() {
		print_hello()
	})

	// Add menu bar to vbox
	vbox.PackStart(mb, false, false, 0)
}

func set_window(win *gtk.Window, fullscreen bool) {
	win.SetPosition(gtk.WIN_POS_CENTER)
	win.SetTitle("Simple Example")
	win.Connect("destroy", func() {
		gtk.MainQuit()
	})

	// Set the default window size.
	win.SetDefaultSize(1280, 720)
	win.SetResizable(false)

	// Make full screen
	if fullscreen {
		win.Fullscreen()
	}
}

func main() {
	// Initialize GTK without parsing any command line arguments.
	gtk.Init(nil)

	// Create a new toplevel window, set its title, and connect it to the
	// "destroy" signal to exit the GTK main loop when it is destroyed.
	win, err := gtk.WindowNew(gtk.WINDOW_TOPLEVEL)
	if err != nil {
		log.Fatal("Unable to create window:", err)
	}

	// Set window properties
	set_window(win, true)

	// Make a new vertically oriented box
	vb, err := gtk.BoxNew(gtk.ORIENTATION_VERTICAL, 5)
	if err != nil {
		log.Fatal("Unable to create button box:", err)
	}

	// Add menu items
	set_menu(vb)

	// Create a drawing area
	// dr, err := gtk.DrawingAreaNew()

	// Create a button box
	bb, err := gtk.ButtonBoxNew(gtk.ORIENTATION_HORIZONTAL)
	if err != nil {
		log.Fatal("Unable to create button box:", err)
	}

	// Create a new button
	b, err := gtk.ButtonNewWithLabel("Hello, gotk3!")
	if err != nil {
		log.Fatal("Unable to create button:", err)
	}
	// Connect the button click event to print_hello
	b.Connect("clicked", func() {
		print_hello()
	})

	// Add the button to the button box.
	bb.Add(b)

	// Add the button box to the vertical box
	vb.Add(bb)

	// Add an image
	img, err := gtk.ImageNewFromFile("assets/images/image.png")
	if err != nil {
		log.Fatal("Unable to create image:", err)
	}
	vb.Add(img)

	// Add vertical box to window
	win.Add(vb)

	// Recursively show all widgets contained in this window.
	win.ShowAll()

	// Begin executing the GTK main loop.  This blocks until
	// gtk.MainQuit() is run.
	gtk.Main()
}
