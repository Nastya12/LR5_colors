#include <iostream>
#include <map>
#include <tr1\memory>
using namespace std;

class Color
{
    int red,green,blue;
public:
    Color():red(0) {}
    Color(int a,int b, int c):red(a),green(b),blue(c) {}
    int getRed()
    {
        return red;
    }
    int getGreen()
    {
        return green;
    }
    int getBlue()
    {
        return blue;
    }
    class Object;
};

class Color::Object
{
    Color obj;
public:
    Object(Color &ob):obj(ob) {}
    Color getColor()
    {
        return obj;
    }
};

class colorErr:public exception
{};
class containerEmpty:public exception
{};

int main()
{
    std::tr1::shared_ptr<Color> red (new Color (255,0,0));
    if (red->getRed()>255||red->getGreen()>255||red->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> green (new Color(0,255,0));
    if (green->getRed()>255||green->getGreen()>255||green->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> blue (new Color(0,0,255));
    if (blue->getRed()>255||blue->getGreen()>255||blue->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> black (new Color(0,0,0));
    if (black->getRed()>255||black->getGreen()>255||black->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> white (new Color(255,255,255));
    if (white->getRed()>255||white->getGreen()>255||white->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> paleRed (new Color(255,51,51));
    if (paleRed->getRed()>255||paleRed->getGreen()>255||paleRed->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> paleGreen (new Color(51,255,102));
    if (paleGreen->getRed()>255||paleGreen->getGreen()>255||paleGreen->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> paleBlue (new Color(153,204,255));
    if (paleBlue->getRed()>255||paleBlue->getGreen()>255||paleBlue->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> yellow (new Color(255,255,0));
    if (yellow->getRed()>255||yellow->getGreen()>255||yellow->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> chocolate (new Color(210,105,30));
    if (chocolate->getRed()>255||chocolate->getGreen()>255||chocolate->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> orange (new Color(255,165,0));
    if (orange->getRed()>255||orange->getGreen()>255||orange->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> appleGreen (new Color(142,182,0));
    if (appleGreen->getRed()>255||appleGreen->getGreen()>255||appleGreen->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> azure (new Color(0,127,255));
    if (azure->getRed()>255||azure->getGreen()>255||azure->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> brown (new Color(150,75,0));
    if (brown->getRed()>255||brown->getGreen()>255||brown->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> deepSkyBlue (new Color(0,191,255));
    if (deepSkyBlue->getRed()>255||deepSkyBlue->getGreen()>255||deepSkyBlue->getBlue()>255)
        throw colorErr();
    std::tr1::shared_ptr<Color> lime (new Color(204,255,0));
    if (lime->getRed()>255||lime->getGreen()>255||lime->getBlue()>255)
        throw colorErr();
    map <string,Color> colors;
    string temp;
    colors["red"]=(*red);
    colors["blue"]=(*blue);
    colors["green"]=(*green);
    colors["black"]=(*black);
    colors["white"]=(*white);
    colors["paleRed"]=(*paleRed);
    colors["paleGreen"]=(*paleGreen);
    colors["paleBlue"]=(*paleBlue);
    colors["yellow"]=(*yellow);
    colors["chocolate"]=(*chocolate);
    colors["orange"]=(*orange);
    colors["appleGreen"]=(*appleGreen);
    colors["azure"]=(*azure);
    colors["brown"]=(*brown);
    colors["deepSkyBlue"]=(*deepSkyBlue);
    colors["lime"]=(*lime);
    if(colors.size()==0)
        throw containerEmpty();
    string key;
    cout<<"\n\n ---> Possible colors <---\n\n";
    cout<<" red \n";
    cout<<" blue \n";
    cout<<" green \n";
    cout<<" black \n";
    cout<<" white \n";
    cout<<" paleRed \n";
    cout<<" paleGreen \n";
    cout<<" paleBlue \n";
    cout<<" yellow \n";
    cout<<" chocolate \n";
    cout<<" orange \n";
    cout<<" appleGreen \n";
    cout<<" azure \n";
    cout<<" brown \n";
    cout<<" deepSkyBlue \n";
    cout<<" lime \n\n";

    cout<<"Enter color for obj #1"<<endl;
    cin>>key;
    Color::Object first(colors[key]);
    cout<<"ok."<<endl<<"Enter color for obj #2"<<endl;
    cin>>key;
    Color::Object second(colors[key]);
    cout<<"ok."<<endl<<"Enter color for obj #3"<<endl;
    cin>>key;
    Color::Object third(colors[key]);
    cout<<"\n Object #1 colored by:"<<endl;
    cout<<"["<<first.getColor().getRed()<<"."<<first.getColor().getGreen()<<"."<<first.getColor().getBlue()<<"]"<<endl;
    cout<<"Object #2 colored by:"<<endl;
    cout<<"["<<second.getColor().getRed()<<"."<<second.getColor().getGreen()<<"."<<second.getColor().getBlue()<<"]"<<endl;
    cout<<"Object #3 colored by:"<<endl;
    cout<<"["<<third.getColor().getRed()<<"."<<third.getColor().getGreen()<<"."<<third.getColor().getBlue()<<"]"<<endl;
    cout<<endl<<"Your container:"<<endl;
    map<string,Color>::iterator ii;
    for (ii=colors.begin(); ii!=colors.end(); ii++)
        cout<<ii->first<<":"<<"["<<ii->second.getRed()<<"."<<ii->second.getGreen()<<"."<<ii->second.getBlue()<<"]"<<endl;
    return 0;
}
