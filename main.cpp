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
		container->setStyleClass("yellow-box");

		Wt::WHBoxLayout *hbox = new Wt::WHBoxLayout();
		container->setLayout(hbox);

		Wt::WText *item = new Wt::WText("Item 1");
		item->setStyleClass("green-box");
		hbox->addWidget(item, 1);
  
		item = new Wt::WText("Item 2");
		item->setStyleClass("blue-box");
		hbox->addWidget(item);
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
