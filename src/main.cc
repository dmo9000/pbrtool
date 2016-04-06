#include <gtkmm.h>
#include <iostream>

Gtk::Window* pMainWindow = nullptr;
Gtk::DrawingArea* pDrawingArea = nullptr;
Gtk::Statusbar* pStatusBar = nullptr;

static
void on_button_clicked()
{
  if(pMainWindow)
    pMainWindow->hide(); //hide() will cause main::run() to end.
}

int main (int argc, char **argv)
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  //Load the GtkBuilder file and instantiate its widgets:
  auto refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("glade/default_layout.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 1;
  }

  //Get the GtkBuilder-instantiated Dialog:
  refBuilder->get_widget("applicationwindow1", pMainWindow);
	pMainWindow->set_title("Substance Instainer");
  refBuilder->get_widget("drawingarea1", pDrawingArea);
  pDrawingArea->show_now();
  refBuilder->get_widget("statusbar1", pStatusBar);

	pStatusBar->push("Welcome to Substance Instainer!");

  if(pMainWindow)
  {
    //Get the GtkBuilder-instantiated Button, and connect a signal handler:
    Gtk::ImageMenuItem* pButton = nullptr;
    refBuilder->get_widget("imagemenuitem5", pButton);
    if(pButton)
    {
      pButton->signal_activate().connect( sigc::ptr_fun(on_button_clicked) );
    }

    app->run(*pMainWindow);
  }

  delete pMainWindow;

  return 0;
}