#include <gtk/gtk.h>

#define WINDOW_W (1280)
#define WINDOW_H (720)

static void print_hello(GtkWidget *widget, gpointer data)
{
	g_print("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Window");

	// Set start size, but keep resizable
	// gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_W, WINDOW_H);

	// Fix size (can't make smaller)
	gtk_widget_set_size_request(GTK_WIDGET(window), WINDOW_W, WINDOW_H);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

	// Make full screen
	// gtk_window_fullscreen(GTK_WINDOW(window));

	button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add(GTK_CONTAINER(window), button_box);

	button = gtk_button_new_with_label("Hello World");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_container_add(GTK_CONTAINER(button_box), button);

	gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
