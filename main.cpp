 //Oisin DAke
 //Lav 8
 //Operational Amplifier Circuits


 #include <iostream>
 #include <math.h>


 using namespace std;
 void inA (double Vin, double Rin, double Rf, double *ptr_Av, double *ptr_Vout);
 void inAmp();
 void nonintAmp(double Vin, double R1, double R2 , double *ptr_Av, double *ptr_Vout);
 void noninAmp();




 char menu(void);
 int main()// main progarm
 {
     char input;//store input as char
     cout << "Op Amp calculations"<< endl;//saying to user what the program does
     do
     {
        input = menu();// menu
        switch (input)// switch case statement to call fuctions when certain letter is inputed
         {
            case 'i':   inAmp();
             break;
             case 'n':   noninAmp();
                         break;
             case 'q':   cout <<"End of program press any key to exit"<< endl;
                         break;
             default:    cout << "Choose the right letter:"<<endl;// writing displayed when incorrect letter is picked
                         break;
         }
     }
     while (input != 'q');// the code above is done when input is not equal to q
     return 0;
 }


 char menu(void)
 {


     char input;
 //menu displayed to the user
     cout << "Choose conversion\n"<<
     "i = Inverting Amplifier\n"<<
     "n = Non Inverting Amplifier\n"<<
     "q = quit program.\n" << endl ;
     cin >> input;


     return input;
 }


 void inAmp()


 {
     double Vcc =0 ,Vee =0, Vin=0 ,Rin=0, Rf=0,Av,Vout;
     double *ptr_Av = &Av;
     double *ptr_Vout = &Vout;


     while (Vcc <= 0)//while loop to ensure a value greater  0 is obtained
     {
     cout << "Enter a value for Vcc: ";
     cin >> Vcc;
     }


       while (Vee <= 0)//while loop to ensure a value  0 is obtained
     {
     cout << "Enter a value for Vee: ";
     cin >> Vee;
     }
       while (Vin <= 0)
     {
         cout << "Enter a value for Vin: ";
         cin >> Vin;
     }


     while (Rin <= 0)//while loop to ensure a value greater 0 is obtained
     {
     cout << "Enter a value for Rin: ";
     cin >> Rin;
     }
     while (Rf <= 0)
     {
         cout << "Enter a value for Rf: ";
         cin >> Rf;
     }
     inA( Vin, Rin, Rf, ptr_Av,ptr_Vout);// functions is called
     cout << "\nVoltage Gain" << *ptr_Av << endl;


 if(Vout >= Vee || Vout <= Vcc)// || means a or
     {
 if(Vin <= 0)
 {
 cout << "\n Output voltage is \n\nVout = " << Vcc;
 }
     else
         {
             cout << "\n\n\nOutput voltage is Vout = " << Vee;
         }
     }
     return ;
 }


 void inA(double Vin, double Rin, double Rf, double *ptr_Av, double *ptr_Vout)


 {
    *ptr_Av = -Rf/Rin ;
    *ptr_Vout = *ptr_Av * Vin;


 }


 void noninAmp()
 {
     double Vcc =0 ,Vee =0,Vin=0, R1=0,R2=0,Av,Vout;//declaring
     double *ptr_Av = &Av;
    double *ptr_Vout = &Vout;


     while (Vcc <= 0)//while loop
     {
         cout << "Enter a value for Vcc: ";
         cin >> Vcc;
     }
       while (Vee <= 0)
     {
        cout << "Enter a value for Vee: ";
        cin >> Vee;
     }



       while (Vin <= 0)
     {
         cout << "Enter a value for Vin: ";
        cin >> Vin;
     }
    while (R1 <= 0)
     {
         cout << "Enter a value for R1: ";
         cin >> R1;
     }
       while (R2 <= 0)
    {
         cout << "Enter a value for R2: ";
         cin >> R2;
     }


     nonintAmp( Vin, R1, R2,ptr_Av,ptr_Vout);//Returns values calculated in the correct functions


 	cout << "\nVoltage Gain\t" << *ptr_Av << endl;




     if(Vout >= Vee || Vout <= Vcc)// || means a or


 {
         if(Vin <= 0)
       {
        cout << "\n\nAmplifier is in satutation \n\nVout =\t " << Vcc ;
         }
     else
         {
         cout << "\n\nAmplifier is in satutation \n\nVout =\t " << Vee ;
         }
 }
  cout << "\n Output Voltage \t" << *ptr_Vout << endl;


     return ;
 }


void nonintAmp(double Vin, double R1, double R2, double *ptr_Av, double *ptr_Vout)//to call pointers


 {
    *ptr_Av = 1 + (R2/R1);
    *ptr_Vout = *ptr_Av * Vin;
 }

