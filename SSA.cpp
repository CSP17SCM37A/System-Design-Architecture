#include <iostream> 
#include <cstdio>
#include <conio.h> 
#include <cstdlib> 
#include <string.h>
#include<limits>
using namespace std;
char ch;
int x;

/******Gas Pump1******/
class GasPump1 {

    public:
    void Activate(float a, float b); // the gas pump is activated where a is regular price and b is super price both are floating numbers 
    void Start(); // start the transaction
    void PayCredit(); // pay by credit card	
    void Reject(); // credit card rejected
    void Cancel(); // transaction cancelled
    void Approved(); // credit card approved	
    void Super(); // Super gas selected 
    void Regular(); // Regular gas selected 
    void StartPump(); // start pumping gas
    void PumpGallon(); // one gallan is disposed 	
    void StopPump(); // stop pumping gas	
};

/******GASPUMP-2******/
class GasPump2 {

    public:
    void Activate(int a, int b,int c); // the gas pump is activated where a is regular price and b is super price both are floating numbers 
    void Start(); // start the transaction
    void PayCash(float c1); // pay by cash where c is float
    void Cancel(); // transaction cancelled
    void Super(); // Super gas selected 
    void Premium(); // Premium gas is selected 
    void Regular(); // Regular gas is selected 
    void StartPump(); // start pumping gas 
    void PumpLiter(); // one liter is disposed 
    void Stop(); // stop pumping gas	
    void Receipt(); // Receipt total is printed 
    void NoReceipt(); // No Receipt is printed
};

/******DATASTORE******/

class DataStore { //Abstract DataStore Class
    public:

};


class DataStore1: public DataStore { //DataStore for GasPump1
    public: static float G;
    static float price;
    static float Rprice;
    static float Sprice;
    static float temp_a;
    static float temp_b;
    static float temp_G;
    static float total;
    static float temp_total;
};

class DataStore2: public DataStore { //DataStore for GasPump2
    public: static float L;
    static float price;
    static int Rprice;
    static int Pprice;
    static int Sprice;
    static float c;
    static float cash;
    static float temp_a;
    static float temp_b;
    static float temp_c;
    static float temp_L;
    static float total;
    static int m;
    static int n;
    static int temp_total;
};

/******MDA_EFSM******/

class MDA_EFSM {
    public:
    void Activate();
    void Start();
    void PayType(int t);
    void Reject();
    void Cancel();
    void Approved();
    void StartPump();
    void Pump();
    void StopPump();
    void SelectGas(int g);
    void Receipt();
    void NoReceipt();
    public:
        static int s_list[8];
};

/******STATE******/
class State { // Abstract State Class
    public:
    void Activate();
    void Start();
    void PayType(int t);
    void PayCredit();
    void PayCash();
    void Reject();
    void Cancel();
    void Approved();
    void StartPump();
    void Pump();
    void StopPump();
    void SelectGas(int g);
    void Receipt();
    void NoReceipt();
    int getId(int id);

    public:
        static int id;
};

class Begin: public State // State Begin
    {
        public: void Activate();
    };

class S0: public State //State S0
    {
        public: void Start();
    };

class S1: public State //State S1
    {
        public: void PayCash();
        void PayCredit();
    };

class S2: public State //State S2
    {
        public: void Approved();
        void Reject();
    };

class S3: public State //State S3
    {
        public: void Cancel();
        void SelectGas(int g);
    };

class S4: public State //State S4
    {
        public: void StartPump();
    };

class S5: public State //State S5
    {
        public: void Pump();
        void StopPump();
    };

class S6: public State //State S6
    {
        public: void Receipt();
        void NoReceipt();
    };

/******OUTPUT CLASSES******/
class Output {
    public:
    void StoreData();
    void PayMsg();
    void StoreCash();
    void DisplayMenu();
    void RejectMsg();
    void SetPrice(int g);
    void ReadyMsg();
    void SetInitialValues();
    void PumpGasUnit();
    void GasPumpedMsg();
    void StopMsg();
    void PrintReceipt();
    void CancelMsg();
    void ReturnCash();
};


class StData { //Abstract class for storing data 
    public:
        virtual void st_data() = 0;

};

class StData1: public StData { //Stores data for GasPump1
    public: void st_data();

};
class StData2: public StData { //Stores data for GasPump2
    public: void st_data();

};

class DispMsg { //Abstract class for displaying payment methods available
    public:
        virtual void disp_msg() = 0;

};
class DispMsg1: public DispMsg { //Payment methods available for GasPump1 class
    public: void disp_msg();

};
class DispMsg2: public DispMsg { //Payment methods available for GasPump2 class
    public: void disp_msg();

};


class DispMenu { //Abstract class for displaying list of selections for gas type
    public:
        virtual void disp_menu() = 0;

};
class DispMenu1: public DispMenu { //Displays list of gas type selections available for GasPump1 
    public: void disp_menu();
};
class DispMenu2: public DispMenu { //Displays list of gas type selections available for GasPump2
    public: void disp_menu();
};


class SetIniVal { //Abstract class for setting initial values
    public:
        virtual void setini_val() = 0;
};
class SetIniVal1: public SetIniVal { //Sets the initial values of GasPump1 
    public: void setini_val();
};
class SetIniVal2: public SetIniVal { //Sets the initial values of GasPump2
    public: void setini_val();
};


class PumpGu { //Abstract class for disposing unit of gas and counting
    public:
        virtual void pump_gu() = 0;
};
class PumpGu1: public PumpGu { //Disposes gas in Gallons
    public: void pump_gu();
};
class PumpGu2: public PumpGu { //Disposes gas in Gallons
    public: void pump_gu();
};


class GasPumpMsg { //Abstract class for displaying amount of gas
    public:
        virtual void gaspump_msg() = 0;
};
class GasPumpMsg1: public GasPumpMsg { //Displays the amount of gas disposed for GasPump1
    public: void gaspump_msg();
};
class GasPumpMsg2: public GasPumpMsg { //Displays the amount of gas disposed for GasPump2
    public: void gaspump_msg();
};


/******ABSTRACT FACTORY CLASSES******/
class AbstractFactory {
    public:
    virtual StData * get_data() = 0;
    virtual DispMsg * get_disp_msg() = 0;
    virtual DispMenu * get_disp_menu() = 0;
    virtual SetIniVal * getini_val() = 0;
    virtual PumpGu * get_pump_gu() = 0;
    virtual GasPumpMsg * get_gaspump_msg() = 0;
};
class ConcreteFactory1: public AbstractFactory { //Calls various strategies for GasPump1 in the output processor.
    public: StData * get_data();
    DispMsg * get_disp_msg();
    DispMenu * get_disp_menu();
    SetIniVal * getini_val();
    PumpGu * get_pump_gu();
    GasPumpMsg * get_gaspump_msg();
};
class ConcreteFactory2: public AbstractFactory { //Calls various strategies for GasPump2 in the output processor
    public: StData * get_data();
    DispMsg * get_disp_msg();
    DispMenu * get_disp_menu();
    SetIniVal * getini_val();
    PumpGu * get_pump_gu();
    GasPumpMsg * get_gaspump_msg();
};


/*****variables*****/
int State::id = 0;
/*****methods******/
static void PayCredit(int a[]);
static void PayCash(int a[]);
 

float DataStore1::temp_a;
float DataStore1::temp_b;
float DataStore1::price;
float DataStore1::G;
float DataStore1::total;
float DataStore1::temp_G;
float DataStore1::Sprice;
float DataStore1::Rprice;
float DataStore2::c;
float DataStore2::total;
float DataStore2::temp_L;
int DataStore2::Pprice;
int DataStore2::Rprice;
int DataStore2::Sprice;
float DataStore2::temp_a;
float DataStore2::temp_b;
float DataStore2::temp_c;
float DataStore2::cash;
float DataStore2::price;
float DataStore2::L;
int DataStore2::m;
int DataStore2::n;

DataStore1 DS1; //object of DataStore1 class
DataStore2 DS2; //object of DataStore2 class

int MDA_EFSM::s_list[8] = {};

/*******GasPump1*******/

void GasPump1::Activate(float a, float b) {
    if (a > 0 && b > 0) {
    	
        DS1.temp_a = a;
        DS1.temp_b = b;
        MDA_EFSM m;
        m.Activate();
    }
}

void GasPump1::Start() {
    MDA_EFSM m;
    m.Start();
}

void GasPump1::PayCredit() {
    MDA_EFSM m;
    m.PayType(1);
}

void GasPump1::Reject() {
    MDA_EFSM m;
    m.Reject();
}

void GasPump1::Cancel() {
    MDA_EFSM m;
    m.Cancel();
}

void GasPump1::Approved() {
    MDA_EFSM m;
    m.Approved();
}

void GasPump1::Super() {
    MDA_EFSM m;
    m.SelectGas(2);
}

void GasPump1::Regular() {
    MDA_EFSM m;
    m.SelectGas(1);
}

void GasPump1::StartPump() {
    MDA_EFSM m;
    m.StartPump();
}

void GasPump1::PumpGallon() {
    MDA_EFSM m;
    m.Pump();
}

void GasPump1::StopPump() {
    MDA_EFSM m;
    m.StopPump();
    m.Receipt();
}

/*******GasPump2*******/

void GasPump2::Activate(int a, int b,int c) {
    if (a > 0 && b > 0 && c>0) {
        DS2.temp_a = a;
        DS2.temp_b = b;
        DS2.temp_c = c;
        MDA_EFSM m;
        m.Activate();
    }
}

void GasPump2::Start() {
    MDA_EFSM m;
    m.Start();
}

void GasPump2::PayCash(float c) {
    if (c > 0) {
        DS2.temp_c = c;
        MDA_EFSM m;
        m.PayType(2);
    }
}

void GasPump2::Cancel() {
    MDA_EFSM m;
    m.Cancel();
}

void GasPump2::Super() {
    MDA_EFSM m;
    m.SelectGas(2);
}

void GasPump2::Premium() {
    MDA_EFSM m;
    m.SelectGas(3);
}

void GasPump2::Regular() {
    MDA_EFSM m;
    m.SelectGas(1);
}

void GasPump2::StartPump() {
    MDA_EFSM m;
    m.StartPump();
}

void GasPump2::PumpLiter() {
    MDA_EFSM m;
    if (DS2.cash < ((DS2.L) + 1) * DS2.price) {
        m.StopPump();
    } else {
        m.Pump();

    }
}

void GasPump2::Stop() {
    MDA_EFSM m;
    m.StopPump();
}

void GasPump2::Receipt() {
    MDA_EFSM m;
    m.Receipt();
}

void GasPump2::NoReceipt() {
    MDA_EFSM m;
    m.NoReceipt();
}


/*********MDA_EFSM***********/

void MDA_EFSM::Activate() {
    State St;
    Begin b;
    if (St.getId(St.id) == 0) {
        b.Activate();
        St.id++;
        s_list[St.id] = 1;
    } else {
        cout << "No change" << endl;
    }
}
void MDA_EFSM::Start() {
    State St; //object of State class
    S0 s0; //object of S0 class
    if (St.getId(St.id) == 1 || s_list[St.id] == 1) {
        s0.Start();
        St.id++;
        s_list[St.id] = 2;
    } else {
        cout << "\nNo change" << endl;
    }

}

void MDA_EFSM::PayType(int t){
   if(t==1){
   	DS2.m=t;
   	PayCredit(s_list);
   }
    
   else if(t==2){
      DS2.n=t;
     PayCash(s_list);
 }
}


void PayCredit(int s_list[]) {
    State St;
    S1 s1; //object of S class
    if (St.getId(St.id) == 2 || s_list[St.id] == 2) {
        s1.PayCredit();
        St.id++;
        s_list[St.id] = 3;
    } else {
        cout << "No change" << endl;
    }
}

void PayCash(int s_list[]) {
    State St;
    S1 s1;
    if (St.getId(St.id) == 2 || s_list[St.id] == 2) {
        s1.PayCash();
        St.id = St.id + 2;
        s_list[St.id] = 4;
    } else {
        cout << "No change" << endl;
    }
}
void MDA_EFSM::Approved() {
    State St;
    S2 s2; //object of S2 class
    if (St.getId(St.id) == 3 || s_list[St.id] == 3) {
        s2.Approved();
        St.id++;
        s_list[St.id] = 4;
    } else {
        cout << "No change" << endl;
    }
}

void MDA_EFSM::Reject() {
    State St;
    S2 s2;
    if (St.getId(St.id) == 3 || s_list[St.id] == 3) {
        s2.Reject();
        St.id - 2;
        s_list[St.id] = 1;
    } else {
        cout << "No change" << endl;
    }
}

void MDA_EFSM::Cancel() {
    State St;
    S3 s3; //object of S3 class
    if (St.getId(St.id) == 4 || s_list[St.id] == 4) {
        s3.Cancel();
        St.id - 3;
        s_list[St.id] = 1;
    } else {
        cout << "No change" << endl;
    }
}

void MDA_EFSM::SelectGas(int g) {
    State St;
    S3 s3; //object of S3 class
    if (St.getId(St.id) == 4 || s_list[St.id] == 4) {
        s3.SelectGas(g);
        St.id++;
        s_list[St.id] = 5;
    } else {
        cout << "No change" << endl;
    }
}

void MDA_EFSM::StartPump() {
    State St;
    S4 s4; //object of S4 class
    if (St.getId(St.id) == 5 || s_list[St.id] == 5) {
        s4.StartPump();
        St.id++;
        s_list[St.id] = 6;
    } else {
        cout << "No change" << endl;
    }
}

void MDA_EFSM::Pump() {
    State St;
    S5 s5; //object of S5 class
    if (St.getId(St.id) == 6 || s_list[St.id] == 6) {
        if (DS2.m == 1) {
            s5.Pump();
        } else if (DS2.n == 2) {
            if (DS2.cash < ((DS2.c) + 1) * DS2.price) {
                s5.StopPump();
            } else {
                s5.Pump();
            }
        }

    } else {
        cout << "No change" << endl;
    }
}

void MDA_EFSM::StopPump() {
    State St;
    S5 s5;
    if (St.getId(St.id) == 6 || s_list[St.id] == 6) {
        s5.StopPump();
        St.id++;
        s_list[St.id] = 7;
    } else {
        cout << "No change" << endl;
    }
}

void MDA_EFSM::Receipt() {
    State St;
    S6 s6; //object of S6 class
    if (St.getId(St.id) == 7 || s_list[St.id] == 7) {
        s6.Receipt();
        St.id - 6;
        s_list[St.id] = 1;
    } else {
        cout << "No change" << endl;
    }
}

void MDA_EFSM::NoReceipt() {
    State St;
    S6 s6;
    if (St.getId(St.id) == 7 || s_list[St.id] == 7) {
        s6.NoReceipt();
        St.id - 6;
        s_list[St.id] = 1;
    } else {
        cout << "No change" << endl;
    }
}

/*********STATE CLASSES*******/

void Begin::Activate() {
    cout << "Changed from Begin state to S1" << endl;
    Output op; //object of Output class
    op.StoreData();
}

void S0::Start() {
    cout << "Changed from S0 to S1" << endl;
    Output op;
    op.PayMsg();
}

void S1::PayCash() {
    cout << "Changed from S1 to S3" << endl;
    Output op;
    op.StoreCash();
    op.DisplayMenu();
}

void S1::PayCredit() {
    cout << "Changed from S1 to S2" << endl;
}

void S2::Reject() {
    cout << "Changed from S2 to S0" << endl;
    Output op;
    op.RejectMsg();
}

void S2::Approved() {
    cout << "Changed from S2 to S3" << endl;
    Output op;
   op.DisplayMenu();
}

void S3::Cancel() {
    cout << "Changed from S3 to S0" << endl;
    Output op;
    op.CancelMsg();
    op.ReturnCash();
    
	}

void S3::SelectGas(int g) {
    if (g == 1) {
        cout << "Regular gas selected" << endl;
    } else if (g == 2) {
        cout << "Super gas selected" << endl;
    } else if (g == 3) {
        cout << "Premium gas selected" << endl;
    }
    cout << "Changed from S3 to S4" << endl;
    Output op;
    op.SetPrice(g);
}

void S4::StartPump() {
    cout << "Changed from S4 to S5" << endl;
    Output op;
    op.SetInitialValues();
    op.ReadyMsg();
}

void S5::Pump() {
    cout << "No change of state occured" << endl;
    Output op;
    op.PumpGasUnit();
    op.GasPumpedMsg();
}

void S5::StopPump() {
    cout << "Changed form S5 to S6";
    Output op;
    op.StopMsg();
}

void S6::Receipt() {
    cout << "Changed from S6 to S0" << endl;
    Output op;
    op.PrintReceipt();
    op.ReturnCash();
     
}

void S6::NoReceipt() {
    cout << "Changed from S6 to S0" << endl;
     Output op;
     op.ReturnCash();
     
}


int State::getId(int id) {
    switch (id) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;

        default:

            return -1;

    }
}

/************ABSTRACT Factory CLASSES***********/

void StData1::st_data() {
   cout<<DS1.temp_a <<" "<<DS1.temp_b<<endl;
    DS1.Rprice = DS1.temp_a;
    DS1.Sprice = DS1.temp_b;
    cout << endl << "\nPrice stored" << endl;
    cout << "\nRegular Price: " << DS1.Rprice;
    cout << "\nSuper Price: " << DS1.Sprice;


}

void StData2::st_data() {
    DS2.Rprice = DS2.temp_a;
    DS2.Pprice = DS2.temp_b;
    DS2.Sprice = DS2.temp_c;
    cout << endl << "\nPrice stored" << endl;
    cout << "\nRegular Price:  " << DS2.Rprice;
    cout << "\nPremium Price:  " << DS2.Pprice;
    cout << "\nsuper Price:  " << DS2.Sprice;


}

void DispMsg1::disp_msg() {
    cout << "\nSelect the payment method" << endl;
    cout << "\nPayCredit" << endl;

}

void DispMsg2::disp_msg() {
    cout << "\nSelect the payment method" << endl;
    cout << "PayCash" << endl;
}


void DispMenu1::disp_menu() {
    cout << "\nSelect gas: " << endl;
    cout << "\nRegular" << endl;
    cout << "\nSuper" << endl;
}

void DispMenu2::disp_menu() {
    cout << "\nSelect gas: " << endl;
    cout << "\nRegular" << endl;
    cout << "\nSuper" << endl;
    cout << "\nPremium" << endl;
}

void SetIniVal1::setini_val() {
    DS1.temp_G = 0;
    DS1.total = 0;
}
void SetIniVal2::setini_val() {
    DS2.temp_L = 0;
    DS2.total = 0;
}


void PumpGu1::pump_gu() {
    cout << "\n Gas is pumped in Gallons" << endl;
    DS1.temp_G = (DS1.temp_G) + 1;
    DS1.G = DS1.temp_G;
    cout << "\nUnits of gas disposed in Gallons is: " << DS1.G;
}

void PumpGu2::pump_gu() {
    cout << "\n Gas is pumped in Liters" << endl;
    DS2.temp_L = (DS2.temp_L) + 1;
    DS2.L = DS2.temp_L;
    cout << "\nUnits of gas disposed in Liters is: " << DS2.L;
}

void GasPumpMsg1::gaspump_msg() {
    if (x == 1) {
        DS1.price = DS1.Rprice;
    } else if (x == 2) {
        DS1.price = DS1.Sprice;
    }
    DS1.total = (DS1.price) * DS1.G;
    cout << "\nAmount of gas disposed is: " << DS1.total;
}

void GasPumpMsg2::gaspump_msg() {
    if (x == 1) {
        DS2.price = DS2.Rprice;
    }else if (x == 2) {
        DS2.price = DS2.Sprice;
    } 
	else if (x == 3) {
        DS2.price = DS2.Pprice;
    }
    DS2.total = (DS2.price) * DS2.L;
    cout << "\nAmount of gas disposed is: " << DS2.total;
}


/*******CONCRETE FACTORY 1, CONCRETE FACTORY 2  **********/



StData * ConcreteFactory1::get_data() {
    return new StData1();
}

StData * ConcreteFactory2::get_data() {
    return new StData2();
}


DispMsg * ConcreteFactory1::get_disp_msg() {
    return new DispMsg1();
}
DispMsg * ConcreteFactory2::get_disp_msg() {
    return new DispMsg2();
}


DispMenu * ConcreteFactory1::get_disp_menu() {
    return new DispMenu1();
}
DispMenu * ConcreteFactory2::get_disp_menu() {
    return new DispMenu2();
}


SetIniVal * ConcreteFactory1::getini_val() {
    return new SetIniVal1();
}
SetIniVal * ConcreteFactory2::getini_val() {
    return new SetIniVal2();
}


PumpGu * ConcreteFactory1::get_pump_gu() {
    return new PumpGu1();
}
PumpGu * ConcreteFactory2::get_pump_gu() {
    return new PumpGu2();
}

GasPumpMsg * ConcreteFactory1::get_gaspump_msg() {
    return new GasPumpMsg1();
}
GasPumpMsg * ConcreteFactory2::get_gaspump_msg() {
    return new GasPumpMsg2();
}

/**********OUTPUT FUNCTIONS DEFINED************/

void Output::StoreData() {
    if (ch == '1') {
        ConcreteFactory1 CF1;
        CF1.get_data() -> st_data();
    } else if (ch == '2') {
        ConcreteFactory2 CF2;
        CF2.get_data() -> st_data();
    }

}

void Output::PayMsg() {
     if (ch == '1') {
        ConcreteFactory1 CF1;
        CF1.get_disp_msg() -> disp_msg();
    } else if (ch == '2') {
        ConcreteFactory2 CF2;
        CF2.get_disp_msg() -> disp_msg();
    }
}

void Output::StoreCash() {
    if (ch == '2') {
        DS2.cash = DS2.temp_c;
    }

}

void Output::DisplayMenu() {
   if (ch == '1') {
        ConcreteFactory1 CF1;
        CF1.get_disp_menu() -> disp_menu();
    } else if (ch == '2') {
        ConcreteFactory2 CF2;
        CF2.get_disp_menu() -> disp_menu();
    }
}

void Output::RejectMsg() {
    if (ch == '1' || ch == '2') {
        cout << "\nCredit card not approved" << endl;
    }
}

void Output::SetPrice(int g) {
    if (ch == '1') {
        if (x == 1) {
            DS1.price = DS1.Rprice;
        } else if (x == 2) {
            DS1.price = DS1.Sprice;
        }

    } else if (ch == '2') {
        if (x == 1) {
            DS2.price = DS2.Rprice;
        }else if (x == 2) {
            DS1.price = DS1.Sprice;
        } 
		else if (x == 3) {
            DS2.price = DS2.Pprice;
        }

    }
}

void Output::ReadyMsg() {
   
    if (ch == '1') {
        cout << "\nReady for pumping" << endl;
    }
    if (ch == '2') {
        cout << "\nReady for pumping" << endl;
    }
}

void Output::SetInitialValues() {
   if (ch == '1') {
        ConcreteFactory1 CF1;
        CF1.getini_val() -> setini_val();
    }
    if (ch == '2') {
        ConcreteFactory2 CF2;
        CF2.getini_val() -> setini_val();
    }
}

void Output::PumpGasUnit() {
   if (ch == '1') {
        ConcreteFactory1 CF1;
        CF1.get_pump_gu() -> pump_gu();
    } else if (ch == '2') {
        ConcreteFactory2 CF2;
        CF2.get_pump_gu() -> pump_gu();
    }
}

void Output::GasPumpedMsg() {
     if (ch == '1') {
        ConcreteFactory1 CF1;
        CF1.get_gaspump_msg() -> gaspump_msg();
    }
    if (ch == '2') {
        ConcreteFactory2 CF2;
        CF2.get_gaspump_msg() -> gaspump_msg();
    }
}

void Output::StopMsg() {
   
    if (ch == '1') {
        cout << "\nPumping has been stopped" << endl;
    }
    if (ch == '2') {
        cout << "\nPumping has been stopped" << endl;
    }
}

void Output::PrintReceipt() {
  
    if (ch == '1') {
        cout << "\nReceipt total is: " << DS1.total;
    }
    if (ch == '2') {
        cout << "\nReceipt total is: " << DS2.total;
    }
}

void Output::CancelMsg() {
  
    if (ch == '1') {
        cout << "\nTransaction Cancelled" << endl;
    }
    if (ch == '2') {
        cout << "\nTransaction Cancelled" << endl;
    }
}

void Output::ReturnCash(){
	 
    if (ch == '2') {
       	
       float  p =  DS2.cash-DS2.total;
       
     if(p > 0){
       	cout << "\nReturn Cash : $" <<p<< endl;
	  }
	   else{
	   		cout << "\n No Cash to Return."<<endl; 
	   }
	   DS2.cash=0;
	   	cout << "\n Transaction is completed."<<endl;
      
   }
}

/********TEST DRIVER*********/

int main() {

    GasPump1 gp1; // object of GasPump1 class
    GasPump2 gp2; // object of GasPump2 class
   
    int a,b, c;
    float a1, b1, c1;
    char ch1;
    cout << "\n\t\t\t CS 586 : PROJECT : SPRING 2017" << endl;
    cout << "\n\t\t\t     Anvesh Gangasani " << endl;
    cout << "\n\t\t\t\t  MDA_EFSM" << endl;
    cout << "\n\t\t\t  Press any key to continue" << endl;
    _getch();

   while(true)
   {   
	  
    	 cout << "\n\t\t\t Following are the Gas Pump classes: " << endl;
         cout << "\n\t\t\t 1. GP-1" << endl;
         cout << "\n\t\t\t 2. GP-2" << endl;
    	 cout << "\n\t\t\t  Select GP: ";
         cin >> ch;
         if(ch=='1' || ch=='2'){
         	break;
		 }
  }
   
   
    switch (ch) {
        case '1':
            cout << " \n GasPump1" << endl;
            cout << " \n Menu of Operations\n" << endl;
            cout << "  0. Activate(float, float)" << endl;
            cout << "  1. Start()" << endl;
            cout << "  2. PayCredit" << endl;
            cout << "  3. Reject()" << endl;
            cout << "  4. Cancel()" << endl;
            cout << "  5. Approved()" << endl;
            cout << "  6. Super()" << endl;
            cout << "  7. Regular()" << endl;
            cout << "  8. StartPump()" << endl;
            cout << "  9. PumpGallon()" << endl;
            cout << "  s. StopPump()" << endl;
            cout << "  q. Quit" << endl;


            cout << "          \nGasPump-1 Execution" << endl;
            ch = '1';
            while (ch1 != 'q') {
                cout << "  \nSelect Operation : " ;
                cout << "0-Activate,1-Start,2-PayCredit,3-Reject,4-Cancel,5-Approved"<<endl;
                cout<<"6-Super,7-Regular,8-StartPump, 9-PumpGallon, s-StopPump, q-quit" << endl;
				cin >> ch1;
                switch (ch1) {
                    case '0':
                        { //Activate
                            cout << "  Operation:  Activate(float a1, float b1)" << endl;
                           
                           a1=0;
                            	 cout << "  Enter value of the parameter a1:"<< flush;                     
                           while(!(cin >> a1)){
	               			    	cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input.  Enter value of the parameter a1:: ";
	                        }
                           
                       
                            b1=0;
                         	 cout << "  Enter value of the parameter b1:"<< flush;
                           while(!(cin >> b1)){
	               			    	cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input.  Enter value of the parameter b1:: ";
	                        }	
                            gp1.Activate(a1, b1);
                            break;
                        };

                    case '1':
                        { //Start
                            cout << "  Operation:  Start()" << endl;
                            gp1.Start();
                            break;
                        };

                    case '2':
                        { //PayCredit 
                            cout << "  Operation:  PayCredit()" << endl;
                            gp1.PayCredit();
                            break;
                        };

                    case '3':
                        { //Reject 
                            cout << "  Operation:  Reject()" << endl;
                            gp1.Reject();
                            break;
                        };

                    case '4':
                        { //Cancel
                            cout << "  Operation:  Cancel()" << endl;
                            gp1.Cancel();
                            break;
                        };

                    case '5':
                        { //Approved
                            cout << "  Operation:  Approved()" << endl;
                            gp1.Approved();
                            break;
                        };

                    case '6':
                        { //Super
                            cout << "  Operation:  Super()" << endl;
                            x = 2;
                            gp1.Super();
                            break;
                        };

                    case '7':
                        { //Regular
                            cout << "  Operation:  Regular()" << endl;
                            x = 1;
                            gp1.Regular();
                            break;
                        };


                    case '8':
                        { //StartPump
                            cout << "  Operation:  StartPump()" << endl;
                            gp1.StartPump();
                            break;
                        };

                    case '9':
                        { //PumpGallon
                            cout << "  Operation:  PumpGallon()" << endl;
                            gp1.PumpGallon();
                            break;
                        };

                    case 's':
                        { //StopPump
                            cout << "  Operation:  StopPump()" << endl;
                            gp1.StopPump();
                            break;

                        };
                    case 'q':
                        break;

                } //end switch
            } // end while
            break; //end case 1
        case '2':
            cout << " \n GasPump2" << endl;
            cout << " \n Menu of Operations\n" << endl;
            cout << "  0. Activate(int,int,int)" << endl;
            cout << "  1. Start()" << endl;
            cout << "  2. PayCash(float)" << endl;
            cout << "  3. Cancel()" << endl;
            cout << "  4. Super()" << endl;
            cout << "  5. Premium()" << endl;
            cout << "  6. Regular()" << endl;
            cout << "  7. StartPump()" << endl;
            cout << "  8. PumpLiter()" << endl;
            cout << "  9. Stop()" << endl;
            cout << "  r. Receipt()" << endl;
            cout << "  n. NoReceipt()" << endl;
            cout << "  q. Quit" << endl;
            ch = '1';

            cout << "          \nGasPump-2 Execution" << endl;
            ch = '2';
            while (ch1 != 'q') {
                cout << "  \nSelect Operation : " ;
                cout << " 0-Activate,1-Start,2-PayCash,3-Cancel,4-super,5-Premium,6-Regular" << endl;
				cout<<"7-StartPump,8-PumpLiter,9-Stop,r-Receipt,n-NoReceipt,q-quit" << endl;
                cin >> ch1;
                switch (ch1) {
                    case '0':
                        { //Activate()
                            cout << "  Operation:  Activate(int a, int b,int c)" << endl;
                            cout << "  Enter value of the parameter a:";
                            a=0;
                             	
                            while(!(cin >> a)){  //Taking the parameter as input
	               			    	cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input.  Enter value of the parameter a:: ";
	                        }
                            
                            b=0;
                            
                            cout << "  Enter value of the parameter b:";
                             while(!(cin >> b)){   //Taking the parameter as input
	               			    	cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input.  Enter value of the parameter b:: ";
	                        }
                          	  
                            cout << "  Enter value of the parameter c:";
                            while(!(cin >> c)){      //Taking the parameter as input
	               			    	cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input.  Enter value of the parameter c:: ";
	                        }
                            gp2.Activate(a, b,c);
                            break;
                        };

                    case '1':
                        { //Start
                            cout << "  Operation:  Start()" << endl;
                            gp2.Start();
                            break;
                        };

                    case '2':
                        { //PayCash
                            cout << "  Operation:  PayCash(float c1)" << endl;
                            c1=0;
                            cout << "  Enter value of the parameter c1:"<< flush;
                            while(!(cin >> c1)){      //Taking the parameter as input
	               			    	cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input.  Enter value of the parameter c1:: ";
	                        }
                           
                            gp2.PayCash(c1);
                            break;
                        };

                    case '3':
                        { //Cancel
                            cout << "  Operation:  Cancel()" << endl;
                            gp2.Cancel();
                            break;
                        };
                    case '4':
                        { //Super
                            cout << "  Operation:  Super()" << endl;
                            x = 2;
                            gp2.Super();
                            break;
                        };

                    case '5':
                        { //Premium
                            cout << "  Operation:  Premium()" << endl;
                            x = 3;
                            gp2.Premium();
                            break;
                        };

                    case '6':
                        { //Regular
                            cout << "  Operation:  Regular()" << endl;
                            x = 1;
                            gp2.Regular();
                            break;
                        };

                    case '7':
                        { //StartPump
                            cout << "  Operation:  StartPump()" << endl;
                            gp2.StartPump();
                            break;
                        };

                    case '8':
                        { //PumpLiter
                            cout << "  Operation:  PumpLiter()" << endl;
                            gp2.PumpLiter();
                            break;
                        };


                    case '9':
                        { //StopPump
                            cout << "  Operation:  Stop()" << endl;
                            gp2.Stop();
                            break;

                    case 'r':
                        { //Receipt
                                    cout << "  Operation:  Receipt()" << endl;
                                    gp2.Receipt();
                                    break;

                                    case 'n':
                                        { //NoReceipt
                                            cout << "  Operation:  NoReceipt()" << endl;
                                            gp2.NoReceipt();
                                            break;

                                        };
                                    case 'q':
                                        break;

                                }
                        }
                        break; //end case 2


                } // end switch
            } // end while
    } //end the first switch case
}

