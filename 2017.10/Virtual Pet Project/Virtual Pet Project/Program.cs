//Application Coded By Lucas Naumowicz

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace Virtual_Pet_Project
{
    class Program
    {
        static bool loop;
        static void Main()
        {
            loop = true; //sets up the basic gameplay loop that will allow players to cycle throuhg various actions.
            Player.PetReset(); //Resets everything Pet related to a default state.

            Console.Title = "Virtual PetBoi";

            Game.Start(); //A basic introduction
            Game.CreatePet(); //The creation section of the pet. Basically establishes how players can choose to customize their pet.

            while (loop == true)
            {
                int Menu_Select;
                Console.WriteLine("Welcome To The Pet Menu! Your pets stats are as follows:" +
                    "\nYour score is: " + Player.score +
                    "\nYour Pet is: " + Game.Pet_Name + " the " + Game.Petter +
                    "\nYour Pet is " + Pet.age + " years old." + 
                    "\nYour Pet's skill level is: " + Pet.skill_level +
                    "\nYour total amount of money is " + Player.currency +
                    "\nYour total amount of treats is " + Item.treats +
                    "\nIt is day " + Time.Total_days);

                Console.WriteLine("\n\nWhat would you like to do?");
                Console.WriteLine("1. Feed your Pet \n2. Play with your Pet \n3. Pat your Pet \n4. Give your Pet a treat \n5. Go shopping \n6. Sleep \n\n\n7. Exit Game");
                Menu_Select = Convert.ToInt32(Console.ReadLine());
                    switch (Menu_Select)
                    {
                        case 1:
                        Player.FeedPet();
                            break;
                        case 2:
                        Player.PlayPet();
                            break;
                        case 3:
                        Player.PatPet();
                            break;
                        case 4:
                        Player.GivePetTreat();
                            break;
                        case 5:
                        Store.Buy_Item();
                            break;
                        case 6:
                        Time.New_Day();
                            break;
                        case 7:
                            loop = false;
                            break;
                        default:
                            Console.WriteLine("Invalid Input. Please Try Again.");
                            Console.ReadLine();
                            Console.Clear();
                            break;
                    }
            }

            Console.WriteLine("Thanks for playing!");
            Console.Read();
        }
    }
    class Game
    {
        public static int Pet_Choice;
        public static string Pet_Name;
        public static string Pet_Color;
        public static string Pets_Fav_Food;
        public static int Pet_Size;

        public static string[] Player_Pet_Choice = new string[] {"Dog", "Cat", "Bird" };
        public static string[] Player_Pet_Size = new string[] {"Small", "Medium", "Large" };
        public static string Petter = Player_Pet_Choice[Pet_Choice];
        public static string Petter_Size = Player_Pet_Size[Pet_Size];

        public static void Start()
        {
            Console.WriteLine("Welcome to Virtual PetBoi, a premier virtual pet program.");
            Console.WriteLine("Press Enter to create a pet.");
            Console.ReadKey();
            Console.Clear();
        }
        public static void CreatePet()
        {
            int Correct;


            Pet_Name = "";

            Console.WriteLine("Welcome. Which type of Pet would you like to have?");
            Console.WriteLine("1. A Dog \n2. A Cat \n3. A Bird");
            Pet_Choice = Convert.ToInt32(Console.ReadLine());
            switch (Pet_Choice)
            {
                case 1:
                    Console.WriteLine("You have chosen a Dog");
                    Pet_Choice = 1;
                    Console.WriteLine("Press Enter To Continue...");
                    Console.ReadKey();
                    break;
                case 2:
                    Console.WriteLine("You have chosen a Cat");
                    Pet_Choice = 2;
                    Console.WriteLine("Press Enter To Continue...");
                    Console.ReadKey();
                    break;
                case 3:
                    Console.WriteLine("You have chosen a Bird");
                    Pet_Choice = 3;
                    Console.WriteLine("Press Enter To Continue...");
                    Console.ReadKey();
                    break;
            }
            Console.Clear();

            Console.WriteLine("What should your Pet's name be?");
            Pet_Name = Console.ReadLine();
            Console.WriteLine("Your Pet's Name is " + Pet_Name + ".");
            Console.WriteLine("Press Enter To Continue...");
            Console.ReadKey();
            Console.Clear();

            Console.WriteLine("What should your Pet's color be?");
            Pet_Color = Console.ReadLine();
            Console.WriteLine("Your Pet's Color is " + Pet_Color + ".");
            Console.WriteLine("Press Enter To Continue...");
            Console.ReadKey();
            Console.Clear();

            Console.WriteLine("What should your Pet's favorite food be?");
            Pets_Fav_Food = Console.ReadLine();
            Console.WriteLine("Your Pet's favorite food is " + Pets_Fav_Food + ".");
            Console.WriteLine("Press Enter To Continue...");
            Console.ReadKey();
            Console.Clear();

            Console.WriteLine("Finally, how large would you like your pet to be?f");
            Console.WriteLine("1. Small \n2. Medium \n3. Large");
            Pet_Size = Convert.ToInt32(Console.ReadLine());
            switch (Pet_Size)
            {
                case 1:
                    Console.WriteLine("You have chosen a Small " + Petter);
                    Pet_Size = 1;
                    Console.WriteLine("Press Enter To Continue...");
                    Console.ReadKey();
                    break;
                case 2:
                    Console.WriteLine("You have chosen a Medium " + Petter);
                    Pet_Size = 2;
                    Console.WriteLine("Press Enter To Continue...");
                    Console.ReadKey();
                    break;
                case 3:
                    Console.WriteLine("You have chosen a Large " + Petter);
                    Pet_Size = 3;
                    Console.WriteLine("Press Enter To Continue...");
                    Console.ReadKey();
                    break;
            }
            Console.Clear();

            Console.WriteLine("Your complete pet is a " + Petter_Size + " " + Petter + " who is named " + Pet_Name + "," + " who is the color " + Pet_Color + "," + " who's favorite food is " + Pets_Fav_Food);
            Console.WriteLine("Is this correct?");
            Console.WriteLine("1. Yes! \n2. Nope!");
            Correct = Convert.ToInt32(Console.ReadLine());
            if (Correct == 1)
            {
                Console.WriteLine("Fantastic! Let's get on with the game.");
                Console.WriteLine("Press Enter to continue...");
                Console.ReadKey();
                Console.Clear();
            }
            if (Correct == 2)
            {
                Console.WriteLine("Uh oh, We'd better start over and get it right then.");
                Console.WriteLine("Press Enter to continue...");
                Console.ReadKey();
                Console.Clear();
                CreatePet();
            }
        }

    }
    class Pet : Game
    {
        public static int age;
        public static int skill_level; //10 for the first item unlock, 20 for the second, and 30 for the third.

        public static string[] skills_learned = new string[] {"Play with a Basic Toy","Pet Yourself", "Feed Yourself", "Teach Yourself"}; //Three Hierarchy of skills your pet can learn.
        public static string[] items_aquired = new string[] {"Basic Toy", "Extendo-Arm", "Robot FeedOMatic", "Internet for " + Petter + "s"};


    }
    class Player : Pet
    {
        public static int score;
        public static int currency;
        public static bool obtained_Extendo_Arm;
        public static bool obtained_Robot_Feeder;
        public static bool obtained_PetInternet;
        public static bool has_PlayerPatPet;
        public static bool has_PlayerFedPet;
        public static bool has_GivenTreats;
        public static bool is_spoiled;
        static int spoiled;

        public static void PetReset()
        {
            obtained_Extendo_Arm = false;
            obtained_Robot_Feeder = false;
            obtained_PetInternet = false;

            score = 0;
            currency = 10;
            Item.treats = 2;
            Time.Total_days = 1;
        }

        public static void FeedPet()
        {
            Console.Clear();
            Console.WriteLine("You feed " + Pet_Name + " some nutritious food pellets. " + Pet_Name + " gobbles them up hungrily.");
            Console.ReadLine();
            Console.Clear();
            has_PlayerFedPet = true;
        }

        public static void PlayPet() //goes into a skill training menu
        {
            int selection;
            Console.Clear();
            Console.WriteLine("How would you like to play with " + Pet_Name + "? You can:");
            Console.WriteLine("\n1. Play with a Basic Toy.");
            if (obtained_Extendo_Arm == true)
            {
                Console.WriteLine("\n2. Play with the " + items_aquired[1] + " and learn to " + skills_learned[1] + ".");
            }
            if (obtained_Robot_Feeder == true)
            {
                Console.WriteLine("\n3. Play with the " + items_aquired[2] + " and learn to " + skills_learned[2] + ".");
            }
            if (obtained_PetInternet == true)
            {
                Console.WriteLine("\n4. Play with the " + items_aquired[3] + " and learn to " + skills_learned[3] + ".");
            }
            Console.WriteLine("\n\nWhich will you choose? Type a number then press enter.");
            selection = Convert.ToInt32(Console.ReadLine());
            if (selection > 1 && obtained_Extendo_Arm == true)
            {
                switch(selection)
                {
                    case 2:
                        Console.WriteLine("You decide to train " + Pet_Name + " with the Extendo Arm.");
                        skill_level = skill_level + 3;
                        Console.WriteLine("Your pet's skill level is now: " + skill_level);
                        Console.WriteLine("Press Enter To Continue...");
                        Console.ReadKey();
                        Console.Clear();
                        break;
                }
            }
            if (selection > 1 && obtained_Robot_Feeder == true)
            {
                switch (selection)
                {
                    case 3:
                        Console.WriteLine("You decide to train " + Pet_Name + " with the FeedOMatic.");
                        skill_level = skill_level + 4;
                        Console.WriteLine("Your pet's skill level is now: " + skill_level);
                        Console.WriteLine("Press Enter To Continue...");
                        Console.ReadKey();
                        Console.Clear();
                        break;
                }
            }
            if (selection > 1 && obtained_PetInternet == true)
            {
                switch (selection)
                {
                    case 3:
                        Console.WriteLine("You decide to train " + Pet_Name + " with the Internet.");
                        skill_level = skill_level + 5;
                        Console.WriteLine("Your pet's skill level is now: " + skill_level);
                        Console.WriteLine("Press Enter To Continue...");
                        Console.ReadKey();
                        Console.Clear();
                        break;
                }
            }
            if (selection == 1)
            {
                Console.WriteLine("You decide to train " + Pet_Name + " with the Basic Toy.");
                skill_level = skill_level + 2;
                Console.WriteLine("Your pet's skill level is now: " + skill_level);
                Console.WriteLine("Press Enter To Continue...");
                Console.ReadKey();
                Console.Clear();
            }
            else
            {
                Console.WriteLine("That is not a proper response. Please select another choice. Press Enter to continue...");
                Console.ReadLine();
                Console.Clear();
                PlayPet();
            }
        }

        public static void PatPet() //gives +10 points per day
        {
            Console.Clear();
            Console.WriteLine("You pat " + Pet_Name + " on the head. It seems to enjoy it greatly :^)");
            Console.WriteLine("Press Enter To Continue...");
            Console.ReadLine();
            Console.Clear();
            has_PlayerPatPet = true;
        }
        public static void GivePetTreat() //+10 points if done once a day, -5 for every instance done more that once a day (spoiling pet)
        {
            if (has_GivenTreats == false)
            {
                Console.Clear();
                Console.WriteLine("You give " + Pet_Name + " their favorite food, " + Pets_Fav_Food + ". " + Pet_Name + " wolfs it down, the happily rolls over. How cute!");
                Console.WriteLine("Press Enter to Continue");
                Console.ReadLine();
                Console.Clear();
                has_GivenTreats = true;
            }
            else
            {
                Console.Clear();
                Console.WriteLine("You give " + Pet_Name + " their favorite food, " + Pets_Fav_Food + ". At this rate, you'll be spoiling the poor thing! You should probably not give " + Pet_Name + " more than one treat a day.");
                Console.WriteLine("Press Enter to Continue");
                Console.ReadLine();
                Console.Clear();
                is_spoiled = true;
                spoiled++;

            }
        }
        public static void Calculate_Score()
        {
            if (has_PlayerFedPet == true)
            {
                score = score + 10;
            }
            if (has_PlayerFedPet == false)
            {
                score = score - 10;
            }
            if (has_PlayerPatPet == true)
            {
                score = score + 10;
            }
            if (has_GivenTreats == true && is_spoiled == false)
            {
                score = score + 10;
            }
            if (is_spoiled == true)
            {
                score = score - (5 * spoiled);
            }
        }
        public static void BoolReset() //Resets the bools every day so that the correct scores can be tallied.
        {
            has_PlayerPatPet = false;
            has_PlayerFedPet = false;
            has_GivenTreats = false;
            is_spoiled = false;
        }
    }
    class Time : Player
    {
        static int day_number;
        public static int Total_days;

        public static void YearCheck()
        {
            if (day_number == 30)
            {
                age++;
                Console.WriteLine("Congratulations! " + Pet_Name + " is now " + age + "!");
                day_number = 0;
            }
        }
        public static void TotalDay()
        {
            Total_days = day_number + (age * 30);
        }
        public static void New_Day()
        {
            Console.Clear();
            TotalDay();
            YearCheck();
            day_number++;
            currency = currency + 10;
            Console.WriteLine("You earn 10$ for unrelated work.");
            Console.WriteLine("Press Enter To End Day");
            Console.ReadLine();
            Calculate_Score();
            BoolReset();
            Console.Clear();
        }
    }
    class Item : Time
    {     
        public static int treats;

        public void Check_inventory()
        {
            Console.WriteLine("You have: " + treats + " treats.");
        }
        public void Item_Functions()
        {
            if (obtained_Extendo_Arm == true)
            {
                has_PlayerPatPet = true;
            }
            if (obtained_Robot_Feeder == true)
            {
                has_PlayerFedPet = true;
            }
            if (obtained_PetInternet == true)
            {

            }
        }
    }
    class Store : Item
    {
        int[] Toy_Cost = new int[] {10,20,30}; //change these to ints that make sense economically.
        static int Treat_Cost;
        static int NumberofTreats;
        static int StoreChoice;


        public static void Buy_Item()
        {
            Console.Clear();
            Treat_Cost = 1;
            Console.WriteLine("What would you like to buy?");
            Console.WriteLine("Treats cost 1$ each and toys may vary.");
            Console.WriteLine("1. Treats \n2. A toy \n3. Leave");
            StoreChoice = Convert.ToInt32(Console.ReadLine());
            switch (StoreChoice)
            {
                case 1:
                    Console.WriteLine("How many would you like? Please Enter the number");
                    if (currency < NumberofTreats)
                    {
                        Console.WriteLine("I'm sorry, you don't have enough money for that many treats.");
                    }
                    if (currency > NumberofTreats)
                    {
                        currency = currency - NumberofTreats;
                        treats = treats + NumberofTreats;
                        Console.WriteLine("Certainly! You now have " + treats + " treats and " + currency + " dollars.");
                    }
                    break;
                case 2:
                    Console.WriteLine("For these toys, we don't accept regular types of currency. We'd rather see some skillful pets before we give you these.");
                    if (skill_level > 10 && obtained_Extendo_Arm == false)
                    {
                        Console.WriteLine("We have a fancy Extendo-Arm. Very useful for pets as they automatically pet themselves in case you might forget to or be too busy.");
                        Console.WriteLine("It looks like your pet might just be ready for this one. Take it! It's on the house.");
                        obtained_Extendo_Arm = true;
                        Buy_Item();
                    }
                    if (skill_level > 20 && obtained_Robot_Feeder == false)
                    {
                        Console.WriteLine("Now with this here fancy Robot FeedOMatic your pet will be able to feed themselves! Never will you have to worry about lifting a finger feeding them again. With the FeedOMatic, your pet is as good as fed garunteed.");
                        Console.WriteLine("It looks like your pet might just be ready for this one. Take it! It's on the house.");
                        obtained_Robot_Feeder = true;
                        Buy_Item();
                    }
                    if (skill_level > 30 && obtained_PetInternet == false)
                    {
                        Console.WriteLine("Now here we've got ourselves a fancy little tablet that allows your pet to have " + "Internet for " + Petter + "s." + "With the vast wealth of knowlage on the internet, your pet can surely gain unlimited amounts of knowlage and may even surprise you with fancy facts here and there!");
                        Console.WriteLine("It looks like your pet might just be ready for this one. Take it! It's on the house.");
                        obtained_PetInternet = true;
                        Buy_Item();
                    }
                    if (obtained_Extendo_Arm & obtained_Robot_Feeder & obtained_PetInternet == true)
                    {
                        Console.WriteLine("Well, it looks like you've gotten everything we have to offer your pet! At this point I'm suprised " + Pet_Name + " isn't doing your taxes for you; The dang thing is a genius!");
                        Buy_Item();
                    }
                    else
                        Console.WriteLine("Well, it looks like your pet isn't quite skilled enough for anything yet. Come back again sometime when your " + Petter + " has wisened up some.");
                        Buy_Item();
                    break;
                case 3:
                    Console.WriteLine("Come back sometime soon!");
                    Console.ReadLine();
                    Console.Clear();
                    break;
            }

        }
    }
}