#include <Wt/WAnchor>
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WLink>
#include <Wt/WText>
#include <Wt/WImage>
#include <Wt/WHBoxLayout>
#include <Wt/WTable>
#include <Wt/WTableCell>
#include <Wt/WLineEdit>


//HEY!
using namespace Wt;
namespace {
    struct Employee {
	std::string firstName;
	std::string lastName;
	double pay;

        Employee(const std::string& aFirstName, 
		 const std::string& aLastName,
		 double aPay)
	  : firstName(aFirstName),
	    lastName(aLastName),
	    pay(aPay) { }
    };

    Employee employees[] = {
      Employee("Mark", "Otto", 100),
      Employee("Jacob", "Thornton", 50),
      Employee("Larry the Bird", "", 10)
    };
}

class ControlExample: public WApplication {
private:
    std::string appName;
    WContainerWidget* _content;

public:
    ControlExample(const WEnvironment &env): WApplication(env) {
        appName = "RateYourBook";
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
        header->addWidget(new WText("<h2>" + appName + "</h2>"));
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
		
		

	

		WTable *table = new Wt::WTable();
		table->setHeaderCount(1);
		table->setWidth(Wt::WLength("100%"));

		table->elementAt(0, 0)->addWidget(new Wt::WText("#"));
		table->elementAt(0, 1)->addWidget(new Wt::WText("First Name"));
		table->elementAt(0, 2)->addWidget(new Wt::WText("Last Name"));
		table->elementAt(0, 3)->addWidget(new Wt::WText("Pay"));

	for (unsigned i = 0; i < 3; ++i) {
		Employee& employee = employees[i];
		int row = i + 1;

		table->elementAt(row, 0)
			->addWidget(new Wt::WText(Wt::WString::fromUTF8("{1}")
				  .arg(row)));
		table->elementAt(row, 1)
			->addWidget(new Wt::WText(employee.firstName));
		table->elementAt(row, 2)
			->addWidget(new Wt::WText(employee.lastName));
		table->elementAt(row, 3)
			->addWidget(new Wt::WLineEdit(Wt::WString::fromUTF8("{1}")
				      .arg(employee.pay)));
}

		
		

		
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
