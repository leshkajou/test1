#include <Wt/WAnchor>
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WLink>
#include <Wt/WText>
#include <Wt/WImage>
#include <Wt/WHBoxLayout>


//HEY!
using namespace Wt;

class ControlExample: public WApplication {
private:
    std::string appName;
    WContainerWidget* _content;

public:
    ControlExample(const WEnvironment &env): WApplication(env) {
        appName = "Application Name";
        setTitle(appName);
        _content = 0;
        internalPathChanged().connect(this, &ControlExample::onInternalPathChange);

        header();
        home();
        sidebar();
        footer();
    }

    WContainerWidget* content() {
        if (_content == 0) {
            _content = new WContainerWidget(root());
            _content->setId("content");
        }
        return _content;
    }

    void onInternalPathChange() {
        content()->clear();
        if (internalPath() == "/") {
            home();
        }
        else if (internalPath() == "/page1") {
            page1();
        }
    }

    void header() {
        WContainerWidget* header = new WContainerWidget(root());
        header->setId("header");
        header->addWidget(new WText("<h1>" + appName + "</h1>"));
    }

    void sidebar() {
        WContainerWidget* sidebar = new WContainerWidget(root());
        sidebar->setId("sidebar");
        sidebar->addWidget(new WText("Sidebar Information"));
    }

    void footer() {
        WContainerWidget* footer = new WContainerWidget(root());
        footer->setId("footer");
        footer->addWidget(new WText("Developed using C++/Wt"));
    }

    void home() {
        WText *t = new WText("<strong>Home</strong> content and a link to <a href='#/page1'>page1</a>");
        t->setInternalPathEncoding(true);
        content()->addWidget(t);
		
		

		Wt::WContainerWidget *container = new Wt::WContainerWidget();

		// Create a navigation bar with a link to a web page.
		Wt::WNavigationBar *navigation = new Wt::WNavigationBar(container);
		navigation->setTitle("Corpy Inc.",
		     "http://www.google.com/search?q=corpy+inc");
		navigation->setResponsive(true);

		Wt::WStackedWidget *contentsStack = new Wt::WStackedWidget(container);
		contentsStack->addStyleClass("contents");

		// Setup a Left-aligned menu.
		Wt::WMenu *leftMenu = new Wt::WMenu(contentsStack, container);
		navigation->addMenu(leftMenu);

		Wt::WText *searchResult = new Wt::WText("Buy or Sell... Bye!");

		leftMenu->addItem("Home", new Wt::WText("There is no better place!"));
		leftMenu->addItem("Layout", new Wt::WText("Layout contents")) //
		leftMenu->setLink(Wt::WLink(Wt::WLink::InternalPath, "/layout"));
		leftMenu->addItem("Sales", searchResult);

		// Setup a Right-aligned menu.
		Wt::WMenu *rightMenu = new Wt::WMenu();
		navigation->addMenu(rightMenu, Wt::AlignRight);

		// Create a popup submenu for the Help menu.
		Wt::WPopupMenu *popup = new Wt::WPopupMenu();
		popup->addItem("Contents");
		popup->addItem("Index");
		popup->addSeparator();
		popup->addItem("About");

		popup->itemSelected().connect(std::bind([=] (Wt::WMenuItem *item) {
		Wt::WMessageBox *messageBox = new Wt::WMessageBox
		("Help",
		Wt::WString::fromUTF8("<p>Showing Help: {1}</p>").arg(item->text()),
		Wt::Information, Wt::Ok);

		messageBox->buttonClicked().connect(std::bind([=] () {
		delete messageBox;
    }));

    messageBox->show();
}, std::placeholders::_1));

Wt::WMenuItem *item = new Wt::WMenuItem("Help");
item->setMenu(popup);
rightMenu->addItem(item);

// Add a Search control.
Wt::WLineEdit *edit = new Wt::WLineEdit();
edit->setEmptyText("Enter a search item");

edit->enterPressed().connect(std::bind([=] () {
    leftMenu->select(2); // is the index of the "Sales"
    searchResult->setText(Wt::WString("Nothing found for {1}.")
			  .arg(edit->text()));
}));

navigation->addSearch(edit, Wt::AlignRight);

container->addWidget(contentsStack);
		

		
    }

    void page1() {
        content()->addWidget(new WText("<strong>Home</strong> content and a link to "));
        WAnchor* a = new WAnchor(WLink(WLink::InternalPath, "/"), "home", content());
    }

};

WApplication* createApplication(const WEnvironment &env) {
	WApplication* tmp = new ControlExample(env);
	tmp->styleSheet().addRule("#header", "background-color: #262626; color: #fff; padding: 0.1em 0.5em;");
	tmp->styleSheet().addRule("#content", "display: inline-block; width: 65%; padding: 0.5em;");
	tmp->styleSheet().addRule("#sidebar", "display: inline-block; width: 30%; padding: 0.5em;");
	tmp->styleSheet().addRule("#footer", "background-color: #262626; color: #fff; padding: 0.5em;");
	tmp->styleSheet().addRule("BODY", "background-color: #F0F8FF;");
    return tmp;
}

int main(int argc, char** argv) {
    return WRun(argc, argv, &createApplication);
}
