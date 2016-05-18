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
#include <Wt/WBreak>
#include <Wt/WMenu>
#include <Wt/WStackedWidget>
#include <Wt/WTextArea>
#include <Wt/WGroupBox>
#include <Wt/WText>
#include <Wt/WVBoxLayout>
#include <Wt/Dbo/Dbo>
#include <string>
#include "bestbook.h"
#include <Wt/Dbo/backend/Sqlite3>

//HEY!
using namespace Wt;


class ControlExample: public WApplication {
private:
    std::string appName;
    WContainerWidget* _content;
	
	
	//Wt::Dbo::backend::Sqlite3 sqlite3;
    Dbo::Session session;

public:
    ControlExample(const WEnvironment &env): WApplication(env) {
        appName = "RateYourBook";
        setTitle(appName);
        _content = 0;
        internalPathChanged().connect(this, &ControlExample::onInternalPathChange);
		Dbo::backend::Sqlite3 DataBase=WApplication::instance()->appRoot() + "myapp.db";
		session.setConnection(DataBase);
		session.mapClass<BestBook>("BestBook");
		Dbo::Transaction transaction(session);
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
/* CREATING HEADER */
    void header() {
        WContainerWidget* header = new WContainerWidget(root());
        header->setId("header");
	header->addStyleClass("centered-example");
        header->addWidget(new WText("<h1>"  + appName + "</h1>")); 
	
    }
/* CREATING SIDEBAR MENU */
    void sidebar() {
        WContainerWidget* sidebar = new WContainerWidget(root());
        sidebar->setId("sidebar");
        sidebar->addWidget(new WText("Sidebar Menu"));
//##### SideBarMenu
		WGroupBox *groupBox = new Wt::WGroupBox();
		groupBox->addStyleClass("centered-example");
//
		WText *authors = new WText("<a href='#/page1'><strong>authors</strong></a><br /><br />");
			authors->setInternalPathEncoding(true);
			groupBox->addWidget(authors);
//
		WText *types = new WText("<a href='#/page1'><strong>types of books</strong></a><br /><br />");
			types->setInternalPathEncoding(true);
			groupBox->addWidget(types);
//
		WText *rates = new WText("<a href='#/page1'><strong>rates</strong></a><br /><br />");
			rates->setInternalPathEncoding(true);
			groupBox->addWidget(rates);
//
		WText *newbook = new WText("<a href='#/page1'><strong>add new book</strong></a><br /><br />");
			newbook->setInternalPathEncoding(true);
			groupBox->addWidget(newbook);
//
		WText *series = new WText("<a href='#/page1'><strong>series and cycles</strong></a><br /><br />");
			series->setInternalPathEncoding(true);
			groupBox->addWidget(series);
//
		WText *reviews = new WText("<a href='#/page1'><strong>wait for reviews</strong></a><br /><br />");
			reviews->setInternalPathEncoding(true);
			groupBox->addWidget(reviews);
//
		WText *newauthor = new WText("<a href='#/page1'><strong>add new author</strong></a><br /><br />");
			newauthor->setInternalPathEncoding(true);
			groupBox->addWidget(newauthor);
//
		sidebar->addWidget(groupBox);
// ############### end of sidebar menu
    }
/* CREATING FOOTER */
    void footer() {
        WContainerWidget* footer = new WContainerWidget(root());
        footer->setId("footer");
        footer->addWidget(new WText("Developed using C++/Wt"));
    }
/* CREATING CONTENT OF THE HOMEPAGE */
    void home() {
        WText *t = new WText("<strong>Home</strong> content and a link to <a href='#/page1'>page1</a>");
        t->setInternalPathEncoding(true);
        content()->addWidget(t);
// ################ TABLE OF TOP BEST BOOKS ##################
	WTable *table = new WTable();
		table->setWidth(Wt::WLength("100%"));
		table->setHeaderCount(1);

		table->elementAt(0, 0)->addWidget(new WText("#"));
		table->elementAt(0, 1)->addWidget(new WText("Book"));
		table->elementAt(0, 2)->addWidget(new WText("Author"));
		table->elementAt(0, 3)->addWidget(new WText("Mark"));
	

	Dbo::Transaction transaction(session);
	Dbo::ptr<BestBook> joe = session.find<BestBook>().where("name = ?").bind("Joe");
	transaction.commit();	
	new WText(joe->password, table->elementAt(1, 0));
		table->addStyleClass("table form-inline");


	content()->addWidget(table);	
 }
/* CREATING NEW PAGE */
    void page1() {
        content()->addWidget(new WText("<strong>Home</strong> content and a link to "));
        WAnchor* a = new WAnchor(WLink(WLink::InternalPath, "/"), "home", content());
    }

};
/* GRAPH SKIN */
WApplication* createApplication(const WEnvironment &env) {
	WApplication* tmp = new ControlExample(env);
	tmp->styleSheet().addRule("#header", "background-color: #262626; color: #fff; padding: 0.1em 0.5em;");
	tmp->styleSheet().addRule("#content", "display: inline-block; width: 65%; padding: 0.5em;");
	tmp->styleSheet().addRule("#sidebar", "display: inline-block; width: 30%; color: #141343; padding: 0.1em 0.5em;");
	tmp->styleSheet().addRule("#footer", "background-color: #262626; color: #fff; padding: 0.5em;");
	tmp->styleSheet().addRule("BODY", "background-color: #F0F8FF;");
	
    return tmp;
}

int main(int argc, char** argv) {
    return WRun(argc, argv, &createApplication);
}
