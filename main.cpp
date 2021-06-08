#include <iostream>
#include <algorithm>
using namespace std;


const int GRADS = 100;  // constant, number of volunteers
// Checks if the total number of volunteers is 100
void checkTotal(int total)
{
  if(total != GRADS)
  {
    cout << "Invalid number of volunteers.\n\n";
    exit(1);
  }
}
// ----------------------------------------------------------------------------
// Gets user choice of to match based on either language or specialization
char getChoice()
{
  char choice;
  cout << "What would you like to match? " << endl
  << "A) Language.\nB) Specialization.\nChoice: ";
  cin >> choice;
  return choice;
}
// ----------------------------------------------------------------------------
// If user chooses language
char choiceLang()
{
  char choice;
  cout << "Choose the language: \n"
  << "A) Spanish.\nB) Japanese.\nC) German.\nD) English.\nE) French.\nF) Italian.\nG) Portugese.\nChoice: ";
  cin >> choice;
  return choice;
}
// ----------------------------------------------------------------------------
//If user chooses specialization
char choiceSpec()
{
  char choice;
  cout << "Choose the specialization: \n"
  << "A) Dermatology.\nB) Cardiology.\nC) Neurology.\nD) Pediatrics.\nE) Anestheology.\nChoice: ";
  cin >> choice;
  return choice;
}
// ----------------------------------------------------------------------------
// Outputs probability of matching Dermatoligists
void derm(int spanDerm, int japDerm, int deuDerm)
{
  cout << "The probability is " << double(spanDerm + japDerm + deuDerm) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probability of matching Cardiologists
void card(int spanCard, int engCard)
{
   cout << "The probability is " << double(spanCard + engCard) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probability of matching Neuroligists
void neur(int freNeur, int engNeur, int deuNeur)
{
  cout << "The probability is " << double(freNeur + engNeur + deuNeur) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probability of matching Pediatricians
void ped(int japPed, int itaPed)
{
  cout << "The probability is " << double(japPed + itaPed) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probability of matching Anestheologists
void anes(int porAnes, int freAnes, int engAnes, int japAnes)
{
  cout << "The probability is " << double(porAnes + freAnes + engAnes + japAnes) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probability of matching Spanish speakers
void span(int spanDerm, int spanCard)
{
  cout << "The probability is " << double(spanDerm + spanCard) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probability of matching Japanese speakers
void jap(int japDerm, int japPed, int japAnes)
{
  cout << "The probability is " << double(japDerm + japPed + japAnes) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probability of matching German speakers
void deu(int deuDerm, int deuNeur)
{
  cout << "The probability is " << double(deuDerm + deuNeur) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probabilty of matching English speakers
void eng(int engCard, int engNeur, int engAnes)
{
  cout << "The probability is " << double(engCard + engNeur + engAnes) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probabilty of matching French speakers
void fre(int freNeur, int freAnes)
{
  cout << "The probability is " << double(freNeur + freAnes) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probabilty of matching Italian speakers
void ita(int itaPed)
{
  cout << "The probability is " << double(itaPed) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Outputs probability of matching Portugese speakers
void por(int porAnes)
{
  cout << "The probability is " << double(porAnes) / double(GRADS);
}
// ----------------------------------------------------------------------------
// Driver code
int main() 
{
  char match;
  char choice;
  char run; 
  //Dermatologists
  int spanDerm = 5; //Spanish speaking Dermatoligists
  int japDerm = 8;  //Japanese speaking Dermatologists
  int deuDerm = 1;  //German speaking Dermatoligist
  //Cardiologists
  int spanCard = 15;  // Spanish Cardiologists
  int engCard = 27;   // English Cardiologists
  //Neuroligists
  int freNeur = 3;  // French Neuroligists
  int engNeur = 12; // English Neurologists
  int deuNeur = 6;  // German Neurologists
  //Pediatricians
  int japPed = 5; // Japanese Pediatricians
  int itaPed = 2; // Italian Pediatricians
  //Anestheologists
  int porAnes = 1; //Portugese Anestheologist
  int freAnes = 9; //French Anestheologists
  int engAnes = 4; //English Anestheologists
  int japAnes = 2; //Japanese Anestheologists

  int total = spanDerm + japDerm + deuDerm + spanCard + engCard + freNeur + engNeur + deuNeur + japPed + itaPed + porAnes + freAnes + engAnes + japAnes;

  do{
  checkTotal(total);
  match = getChoice();

  if (toupper(match) == 'A')
  {
    choice = choiceLang();
    switch (toupper(choice))
    {
      case 'A':
        span(spanDerm, spanCard);
        break;
      case 'B':
        jap(japDerm, japPed, japAnes);
        break;
      case 'C':
        deu(deuDerm, deuNeur);
        break;
      case 'D':
        eng(engCard, engNeur, engAnes);
        break;
      case 'E':
        fre(freNeur, freAnes);
        break;
      case 'F':
        ita(itaPed);
        break;
      case 'G':
        por(porAnes);
    }
  }
  else if (toupper(match) == 'B')
  {
    choice = choiceSpec();
    switch (toupper(choice))
    {
      case 'A':
        derm(spanDerm, japDerm, deuDerm);
        break;
      case 'B':
        card(spanCard, engCard);
        break;
      case 'C':
        neur(freNeur, engNeur, deuNeur);
        break;
      case 'D':
        ped(japPed, itaPed);
        break;
      case 'E':
        anes(porAnes, freAnes, engAnes, japAnes);
        break;
    }

  }
  cout << endl << "Would you like to run the program again? (Y / N) ";
  cin >> run;
  cout << "\033[2J\033[1;1H";
  } while (toupper(run) == 'Y');
  cout << "Shutting down... Goodbye\n\n";
  exit(1);
  return 0;
}