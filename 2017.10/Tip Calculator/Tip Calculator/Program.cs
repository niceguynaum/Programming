//Tip Calculator by Lucas Naumowicz

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tip_Calculator
{
    class Program
    {
        static void Main()
        {
            Console.Title = "Tip Calculatron";
            Console.WriteLine("Welcome to Tip Calculatron! (Press Enter to Continue)");
            Console.ReadKey();
            Console.Clear();


            Scenerio_Picker.Scenerio_Pick();
        }
    }
    class Scenerio_Picker
    {

        static int choice_selector; //int that determines which tip scenerio is selected. 1-10.
        static int number_of_coats; //special case int to determine cost vs number of coats.
        static int valet_distance; //int to determine which special case to determine how much to pay for valet

        public static void Scenerio_Pick()
        {
            Console.WriteLine("Please select which tipping scenerio is most suitable for your needs:");
            Console.WriteLine("\n1. Bellhops/Doorman." + "\n2. Coatroom Attendants." + "\n3. Waitresses/Waiters" + "\n4. Vallets." + "\n5. Bartenders." + "\n6. Barbers/hairdressers." + "\n7. Taxi Drivers.." + "\n8. Pizza Guys/Food Delivery service." + "\n9. Tour Guides." + "\n10. Bathroom Attendents.");

            choice_selector = Convert.ToInt32(Console.ReadLine());


            if (choice_selector == 1)
            {
                Console.Clear();
                Console.WriteLine("Doormen in the United States are usually present outside of hotels and buildings in larger cities. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a bellhop/doorman is to \n tip them 2$ or more if they help you with your bags. (Press Enter to Continue)");
                Console.ReadKey();
                Console.WriteLine("Your total to tip is 2$.");
            }
            else if (choice_selector == 2)
            {
                Console.Clear();
                Console.WriteLine("Coatroom Attendants typically reside in any establishment that has a coatroom. \nThese will usually be seen in upscale cocktail lounges, casinos, and wedding halls. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a Coatroom Attendant is to \n tip them 1$ per coat. (Press Enter to Continue)");
                Console.ReadKey();
                Console.WriteLine("Please enter the number of coats checked.");
                number_of_coats = Console.Read();
                number_of_coats = number_of_coats * 2;
                Console.Clear();
                Console.WriteLine("Your total to tip is " + number_of_coats);
            }
            else if (choice_selector == 3)
            {
                Console.Clear();
                Console.WriteLine("Waiters and Waitresses can be seen in almost every sit-down eating establishment in the United States.\nThey typically serve food, bring drinks, and also generally accomodate most resturaunt patrons. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a Waiter/Waitress is to pay 15%-25% of the total bill. (Press Enter to Continue)");
                Console.ReadKey();
                Tip_Calculator.Tip_With_Percent();
            }
            else if (choice_selector == 4)
            {
                Console.Clear();
                Console.WriteLine("Valets typically reside in large resturaunts, casinos, and hotels. They allow patrons to not have to worry about parking their cars. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a vallets is to \n tip them 3-5$ when they bring your car back depending on how much effort they went through. (Press Enter to Continue)");
                Console.ReadKey();
                Console.WriteLine("Please select the distance that the valet had to travel: ");
                Console.WriteLine("Please Enter 1,2, or 3.\n1. Near \n2. Far \n3. Very Far.");
                valet_distance = Console.Read();
                switch (valet_distance)
                {
                    case 1:
                        Console.Clear();
                        Console.WriteLine("Tip your valet 3$.");
                        break;
                    case 2:
                        Console.Clear();
                        Console.WriteLine("Tip your valet 4$.");
                        break;
                    case 3:
                        Console.Clear();
                        Console.WriteLine("Tip your valet 5$.");
                        break;
                }

            }
            else if (choice_selector == 5)
            {
                Console.Clear();
                Console.WriteLine("Bartenders are usually found in bars, pubs, and resturuants. Just like waiters and waitresses, their tip total should be calculated based off of the total drink order. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a bartender is to pay 10%-25% of the total bill. (Press Enter to Continue)");
                Console.ReadKey();
                Tip_Calculator.Tip_With_Percent();
            }
            else if (choice_selector == 6)
            {
                Console.Clear();
                Console.WriteLine("Barbers and hairdressers provide a variety of grooming services. They can vary anything from facial hair to regular hair cuts. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a barber is to pay 10%-25% of the total bill. (Press Enter to Continue)");
                Console.ReadKey();
                Tip_Calculator.Tip_With_Percent();
            }
            else if (choice_selector == 7)
            {
                Console.Clear();
                Console.WriteLine("Taxi drivers are found almost everywhere that there is a need for transportation. \nThe first Taxicab service was created by Harry Nathaniel Allen of the New York Taxi Company back in 1907. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a taxicab is to pay 10%-25% of the total travel. (Press Enter to Continue)");
                Console.ReadKey();
                Tip_Calculator.Tip_With_Percent();
            }
            else if (choice_selector == 8)
            {
                Console.Clear();
                Console.WriteLine("Delivery Drivers are most commonly found in fast food resturaunts. As of late, however, there has been a surgance of \ndelivery based apps that allow people to order any type of food then have it delivered. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a delivery driver is to pay 10-20% of the bill in addition to any delivery charges that may occur. (Press Enter to Continue)");
                Console.ReadKey();
                Tip_Calculator.Tip_With_Percent_and_Special();
            }
            else if (choice_selector == 9)
            {
                Console.Clear();
                Console.WriteLine("Tour guides are usually found in tourist heavy areas, historical locations, and theme parks. \nTheir usual itinerary is to show tourists various points of interest and give interesting factoids and trivia. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a tourguide is to pay 10%-25% of the total bill for the tour. (Press Enter to Continue)");
                Console.ReadKey();
                Tip_Calculator.Tip_With_Percent();
            }
            else if (choice_selector == 10)
            {
                Console.Clear();
                Console.WriteLine("Bathroom attendants are found in very upscale places and is more commonly seen in Europe. They tipcally provide people with hot towels, perhaps a mint, and sometime toilet paper rolls if needed. (Press Enter to Continue)");
                Console.ReadKey();

                Console.Clear();
                Console.WriteLine("The typical tipping etiquette for a Bathroom Attendant is to pay 2$. (Press Enter to Continue)");
                Console.ReadKey();
                Console.WriteLine("Your total to tip is 2$.");
            }
            else
            {
                Console.WriteLine("Invalid choice. Please select a valid option.");
                Scenerio_Pick();
            }
        }
    }
    class Tip_Calculator
    {
        static double User_Total; // The amount needed to pay pre tip
        static double Tip_Total; // The amount needed to pay after tip inclusion.
        static double Percentage; // The tip amount percentage
        static double Delivery; //Special Case Charges

        public static void Tip_With_Percent() //a method for calculating and printing out tip percentages and totals.
        {
            Console.WriteLine("Please Enter the Total Bill.");
            User_Total = double.Parse(Console.ReadLine());
            Console.Clear();
            Console.WriteLine("Please enter what tip percentage you would like to select.");
            Percentage = double.Parse(Console.ReadLine());
            Console.Clear();

            Tip_Total = User_Total * (Percentage/100) + User_Total;
            Console.WriteLine("Your total is " + User_Total.ToString("0.00") + " and your tip amount is " + Percentage + ", Therefore your total amount needed to pay is: " + Tip_Total.ToString("0.00"));
        }

        public static void Tip_With_Percent_and_Special() //same as Tip_With_Percent() but adds a special case scenerio that allows you to add additional costs.
        {
            Console.WriteLine("Please Enter the Total Bill.");
            User_Total = double.Parse(Console.ReadLine());
            Console.Clear();
            Console.WriteLine("Please enter what tip percentage you would like to select.");
            Percentage = double.Parse(Console.ReadLine());
            Console.Clear();
            Console.WriteLine("Please enter any delivery charges.");
            Delivery = double.Parse(Console.ReadLine());
            Tip_Total = User_Total * (Percentage / 100) + User_Total + Delivery;
            Console.WriteLine("Your total is " + User_Total.ToString("0.00") + " and your tip amount is " + Percentage + ", and your delivery charge is " + Delivery + ", Therefore your total amount needed to pay is: " + Tip_Total.ToString("0.00"));
        }

    }
}