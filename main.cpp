// ? libraries: 

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

// ? global variables :

std::vector<int> ages;
std::vector<std::string> num;
std::vector<std::string> usernames;
std::vector<std::string> first_names;
std::vector<std::string> last_names;
std::vector<std::string> emails;
std::vector<std::string> passwords;
std::vector <std::string> sexs;
std::vector <std::string> passtest;
std::vector <std::string> hobbies;
std::vector <std::string> jobs;
std::vector <std::string> notification;
std::string for_now_user;
int finding_index;
bool end(false);
// ? classes:

class social_media
{
    private:
        std::string instagram;
        std::string twiter;
        std::string facebook;
    public:
        social_media();
};

class change
{
    private:
        std::string old;
        std::string nuw;
        std::string Cnuw;
        std::string capchar;
        std::string rcaptchar;
    public:
        void set_for_passwords();
        void ver_change_pasword();
        void set_for_email();
        void ver_change_email();
};

class login
{
    private:
        std::string pass;
        std::string user;
    public:
        void get_it();
        void verify();
        std::string get_username();
};

class profile
{
    private:
        std::string username;
        std::string first_name;
        std::string last_name;
        std::string sex;
        std::string email;
        std::string phone_number;
        std::string password;
        std::string clone_password;
        int age;
    public:
        void set_them_all();
        void verify_them_all();
        void add_it_to_database();
        void myProfileSection(int fin);
        void match_profile_section(int fin);
        //friend void Display(notifications ob1, discover ob2, profile ob3);
};

class notifications
{
    public:
        void go_for_notification(std::string name);
        void show_all_notifications();
        //friend void Display(notifications ob1, discover ob2, profile ob3);
};

class discover
{
    private:
        int num_profile;
    public:
        friend void Display(notifications ob1, discover ob2, profile ob3);
};


// ? no reffrence functions :

void load_all();
void main_menu();

void print(std::vector<int> vec)
{
    for(int x : vec) std::cout << x << std::endl;
}

void clear_all_vectors()
{
    usernames.clear();
    first_names.clear();
    last_names.clear();
    sexs.clear();
    emails.clear();
    num.clear();
    passwords.clear();
    ages.clear();
    hobbies.clear();
    jobs.clear();
}

void binder()
{
    std::cout << std::endl << "___________________Binder___________________" << std::endl;
}

void myCursor()
{
    std::cout << std::endl << "-> ";
}

void my_choice_one()
{
    std::string my_choice_1;
    myCursor();
    std::cin >> my_choice_1;
    if(my_choice_1 == "login")
    {
        login o2;
        o2.get_it();
    }
    if(my_choice_1 == "register")
    {
        profile o1;
        o1.set_them_all();
        o1.verify_them_all();
        o1.add_it_to_database();
        login obj1;
        obj1.get_it();
    }
}

void base()
{
    binder();
    load_all();
    std::cout << "hello, user :\n login(have already an account) \n or \n register(create a new account)";
    my_choice_one();
    binder();
}

void drawCircle(int radius)
{
    // Set the center of the circle
    int centerX = radius;
    int centerY = radius;
    // Loop through each row and column
    for (int y = 0; y <= 2 * radius; ++y)
    {
        for (int x = 0; x <= 2 * radius; ++x)
        {
            // Calculate the distance from the current point to the center of the circle
            float distance = std::sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
            // Check if the distance is close to the radius (with some tolerance)
            if (std::abs(distance - radius) < 0.5)
            {
                std::cout << "* ";
            }
            else
            {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

std::string hide_it(std::string str)
{
    int size = str.length();
    for(int i = 0; i < size; i++)
        if(!(i == size - 1 || i == size - 2 || str[i] == *str.begin())) str[i] = '*';
    return str;
}

bool lineaSearch_one(std::vector<std::string> str1, std::string target)
{
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] == target) return true;
    }
    return false;
}

int lineaSearch_two(std::vector<std::string> str1, std::string target)
{
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] == target) return i;
    }
    return 0;
}

int lineaSearch_three(std::vector<int> str1, int target)
{
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] == target) return i;
    }
    return 0;
}

void stor_data_string(std::vector<std::string> str, std::string filename)
{
    std::ofstream file(filename);
    if(file.is_open())
    {
        for(std::string x : str) file << x << '\n';
        file.close();
    }
    else std::cerr << "just to make sure \n";
}

void stor_data_int(std::vector<int> str, std::string filename)
{
    std::ofstream file(filename);
    if(file.is_open())
    {
        for(int x : str) file << x << '\n';
        file.close();
    }
    else std::cerr << "just to make sure (0)\n";
}

void clear_file(std::string filename)
{
    std::ofstream file(filename);
    file << "";
}

void load_values_from_datebase_str(std::vector<std::string> &str ,const std::string &filename)
{
    std::ifstream file(filename);
    if(file.is_open())
    {
        std::string vals;
        while(file >> vals)
            str.push_back(vals);
        file.close();
    }
    else std::cerr << "just to make sure (1)\n";
}

void load_values_from_datebase_int(std::vector<int> &str ,const std::string &filename)
{
    std::ifstream file(filename);
    if(file.is_open())
    {
        int vals;
        while(file >> vals)
            str.push_back(vals);
        file.close();
    }
    else std::cerr << "just to make sure (1)\n";
}

void update_the_database(std::vector<std::string> vec, std::string replace, std::string filename)
{
    vec.clear();
    load_values_from_datebase_str(vec, filename);
    vec[finding_index] = replace;
    clear_file(filename);
    stor_data_string(vec, filename);
}

std::string captcha()
{
    std::string testing_captchar  = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(0));
    std::string captchar;
    for(int i = 0; i < 6; i++)
    {
        captchar += testing_captchar[rand() % 62];
    }
    return captchar;
}

void load_all()
{
    clear_all_vectors();
    load_values_from_datebase_int(ages, "database/ages.txt");
    load_values_from_datebase_str(num, "database/phone numbers.txt");
    load_values_from_datebase_str(usernames, "database/usernames.txt");
    load_values_from_datebase_str(first_names, "database/first names.txt");
    load_values_from_datebase_str(last_names, "database/last names.txt");
    load_values_from_datebase_str(emails, "database/email.txt");
    load_values_from_datebase_str(passwords, "database/passwords.txt");
    load_values_from_datebase_str(sexs, "database/sex.txt");
    load_values_from_datebase_str(jobs, "database/jobs.txt");
    load_values_from_datebase_str(hobbies, "database/hobbies.txt");
}

int for_end(bool en)
{
    return 0;
}

void main_menu()
{
    profile o1;
    notifications o2;
    discover o3;
    binder();
    std::cout << "hello " << for_now_user << ',' << std::endl;
    std::cout << "(1): profile \n"<< "(2): discover. \n";
    std::cout << "(3): notification \n"<< "(4): Social Media Integration \n"<< "(5): Exite. ";
    int my_choice_two;
    myCursor();
    std::cin >> my_choice_two;
    switch (my_choice_two)
    {
    case 1:
    {
        profile o1;
        o1.myProfileSection(finding_index);
    }
    case 2:
    {
        Display(o2, o3, o1);
    }
    case 3:
    {
        o2.show_all_notifications();
    }
    case 4:
    {
        social_media o4;
        main_menu();
    }
    case 5:
        end = true;
        for_end(end);
    }
}

std::string current_time()
{
    std::time_t currentTime = std::time(nullptr);
    std::string timeString = std::ctime(&currentTime);
    return timeString;
}

void Display(notifications ob1, discover ob2, profile ob3)
{
    load_all();
    int profile(1);
    int size = ages.size();
    for(int i = 0; i < size; i++)
    {
        if(i == finding_index) continue;
        if(sexs[i] != sexs[finding_index])
        {
        std::cout << "--------profile N°" << profile << "-------------" << std::endl;
        ob3.match_profile_section(i);
        char my_choice_four;
        std::cout << "match ?? (y : yes/n : no/g : go back):";
        myCursor();
        std::cin >> my_choice_four;
        switch (static_cast<int>(my_choice_four))
        {
        case 121:
            {
                ob1.go_for_notification(first_names[i] + " " + last_names[i]);
                profile++;
                continue;
            }
            break;
        case 110:
        {
            profile++;
            continue;
        }
        case 103:
        {
            main_menu();
            break;
        }
        }
        }
        else continue;
    }
    main_menu();
}

// ? class refference functions:

void profile :: set_them_all()
{
        std::cout << "first name: ";
    myCursor();
    std::cin >> first_name;
        std::cout << "last name: ";
    myCursor();
    std::cin >> last_name;
        std::cout << "username: ";
    myCursor();
    std::cin >> username;
        std::cout << "email : ";
    myCursor();
    std::cin >> email;
        std::cout << "your age ";
    myCursor();
    std::cin >> age;
        std::cout << "sex(male or female): ";
    myCursor();
    std::cin >> sex;
        std::cout << "phone number: ";
    myCursor();
    std::cin >> phone_number;
        std::cout << "insert a password: ";
    myCursor();
    std::cin >> password;
        std::cout << "confirme the password: ";
    myCursor();
    std::cin >> clone_password;
}

void profile :: verify_them_all()
{
    bool ver = (age >= 18 && phone_number[0] == '+' && password == clone_password);
    int counter(0);
    while (!ver && counter < 3)
    {
        if(age < 18)
        {
            std::cerr << "you must be 18 or older to use this app, age: ";
            myCursor();
            std::cin >> age;
        }
        if(phone_number[0] != '+')
        {
            std::cerr << "the phone number must start with a '+' signe, phone number: ";
            myCursor();
            std::cin >> phone_number;
        }
        if(password != clone_password)
        {
            std::cerr << "confirmed password dosen't match the password, password: ";
            myCursor();
            std::cin >> password;
            std::cout << "confirme the password: ";
            myCursor();
            std::cin >> clone_password;
        }
        ver = (age >= 18 && phone_number[0] == '+' && password == clone_password);
        counter++;
    }
    if(ver)
    {
        std::cout << "registration done successfuly :) \n";
        ages.push_back(age);
        num.push_back(phone_number);
        usernames.push_back(username);
        first_names.push_back(first_name);
        last_names.push_back(last_name);
        emails.push_back(email);
        passwords.push_back(password);
    }
    else
    {
        std::cerr << "something went wrong, try again :(";
        base();
    }
}

void profile :: add_it_to_database()
{
    stor_data_int(ages, "database/ages.txt");
    stor_data_string(num, "database/phone numbers.txt");
    stor_data_string(usernames, "database/usernames.txt");
    stor_data_string(first_names, "database/first names.txt");
    stor_data_string(last_names, "database/last names.txt");
    stor_data_string(emails, "database/email.txt");
    stor_data_string(passwords, "database/passwords.txt");
    stor_data_string(sexs, "database/sex.txt");
    stor_data_string(passwords, "database/jobs.txt");
    stor_data_string(sexs, "database/hobbies.txt");
}

void profile :: myProfileSection(int fin)
{
    drawCircle(2);
    std::cout << "no profile picture. \n \n";
    std::cout << "first name: " << first_names[fin] << std::endl;
    std::cout << "last name: " << last_names[fin] << std::endl;
    std::cout << "username: " << usernames[fin] << std::endl;
    std::cout << "email: " << hide_it(emails[fin]) << std::endl;
    std::cout << "sex: " << sexs[fin] << std::endl;
    std::cout << "age: " << ages[fin] << std::endl;
    std::cout << "password: " << hide_it(passwords[fin]) << std::endl;
    std::cout << "phone number: " << hide_it(num[fin]) << std::endl;
    std::cout << "hobbie: " << hobbies[fin] << std::endl;
    std::cout << "job: " << jobs[fin] << std::endl;
    std::cout << "(1): change password " << std::endl;
    std::cout << "(2): change email" << std::endl;
    std::cout << "(3): go back" << std::endl;
    int my_choice_three;
    myCursor();
    std::cin >> my_choice_three;
    switch (my_choice_three)
    {
    case 1:
    {
        change oo3;
        oo3.set_for_passwords();
        oo3.ver_change_pasword();
    }
    break;
    case 2:
    {
        change oo4;
        oo4.set_for_email();
        oo4.ver_change_email();
    }
    break;
    case 3:
        {
            main_menu();
        }
    }
}

void profile :: match_profile_section(int fin)
{
    std::cout << "first name: " << first_names[fin] << std::endl;
    std::cout << "last name: " << last_names[fin] << std::endl;
    std::cout << "username: " << usernames[fin] << std::endl;
    std::cout << "sex: " << sexs[fin] << std::endl;
    std::cout << "age: " << ages[fin] << std::endl;
    std::cout << "hobbie: " << hobbies[fin] << std::endl;
    std::cout << "job: " << jobs[fin] << std::endl;
}

void login :: get_it()
{
    std::cout << "username: ";
    myCursor();
    std::cin >> user;
    std::cout << "password: ";
    myCursor();
    std::cin >> pass;
    verify();
}

void login :: verify()
{
    load_all();
    if(lineaSearch_one(usernames, user))
    {
        int index = lineaSearch_two(usernames, user);
        if(pass == passwords[lineaSearch_two(usernames, user)])
        {
            for_now_user = user;
            finding_index = index;
            main_menu();
        } 
        else
        {
            std::cerr << "This password does not exist in our system" << std::endl;
            get_it();
        }  
    }
    else 
    {
        std::cerr << "This username does not exist in our system" << std::endl;
        get_it();
    }
}

void change :: set_for_passwords()
{
    std::cout << "enter your old password: ";
    myCursor();
    std::cin >> old;
    std::cout << "enter the new password: ";
    myCursor();
    std::cin >> nuw;
    std::cout << "confirme the new password: ";
    myCursor();
    std::cin >> Cnuw;
    rcaptchar = captcha();
    std::cout << "reenter the following captchar: " << rcaptchar;
    myCursor();
    std::cin >> capchar;

}

void change :: ver_change_pasword()
{
    bool checky = (old == passwords[finding_index]) && (nuw == Cnuw) && (capchar == rcaptchar);
    int co(0);
    while(!checky && co < 2)
    {
        if(old != passwords[finding_index])
        {
            std::cerr << "old password wrong, fill for the right old password" << std::endl;
            std::cout << "enter old pass:";
            myCursor();
            std::cin >> old;
        }
        if(nuw != Cnuw)
        {
            std::cerr << "verify your new password !!" << std::endl;
            std::cout << "enter the new password: ";
            myCursor();
            std::cin >> nuw;
            std::cout << "confirme the new password: ";
            myCursor();
            std::cin >> Cnuw;
        }
        if(capchar != rcaptchar)
        {
            rcaptchar = captcha();
            std::cout << "reenter the following captchar: " << rcaptchar;
            myCursor();
            std::cin >> capchar;
        }
        co++;
        checky = (old == passwords[finding_index]) && (nuw == Cnuw) && (capchar == rcaptchar);
    }
    if(checky)
    {
        std::cout << "changes saved successfully :)" << std::endl;
        passwords[finding_index] = nuw;
        update_the_database(passwords, nuw, "database/passwords.txt");
        profile oo1;
        oo1.myProfileSection(finding_index);
    }
    else
    {
        std::cerr << "something went wrong, try again :(" << std::endl;
        profile oo2;
        oo2.myProfileSection(finding_index);
    }
}

void change :: set_for_email()
{
    std::cout << "enter your old email: ";
    myCursor();
    std::cin >> old;
    std::cout << "enter the new email: ";
    myCursor();
    std::cin >> nuw;
    std::cout << "confirme the new email: ";
    myCursor();
    std::cin >> Cnuw;
    rcaptchar = captcha();
    std::cout << "reenter the following captchar: " << rcaptchar;
    myCursor();
    std::cin >> capchar;

}

void change :: ver_change_email()
{
    bool checky = (old == emails[finding_index]) && (nuw == Cnuw) && (capchar == rcaptchar);
    int co(0);
    while(!checky && co < 2)
    {
        if(old != emails[finding_index])
        {
            std::cerr << "old email wrong, fill for the right old email" << std::endl;
            std::cout << "enter old email:";
            myCursor();
            std::cin >> old;
        }
        if(nuw != Cnuw)
        {
            std::cerr << "verify your new email !!" << std::endl;
            std::cout << "enter the new email: ";
            myCursor();
            std::cin >> nuw;
            std::cout << "confirme the new email: ";
            myCursor();
            std::cin >> Cnuw;
        }
        if(capchar != rcaptchar)
        {
            rcaptchar = captcha();
            std::cout << "reenter the following captchar: " << rcaptchar;
            myCursor();
            std::cin >> capchar;
        }
        co++;
        checky = (old == emails[finding_index]) && (nuw == Cnuw) && (capchar == rcaptchar);
    }
    if(checky)
    {
        std::cout << "changes saved successfully :)" << std::endl;
        emails[finding_index] = nuw;
        update_the_database(emails, nuw, "database/email.txt");
        profile oo1;
        oo1.myProfileSection(finding_index);
    }
    else
    {
        std::cerr << "something went wrong, try again :(" << std::endl;
        profile oo2;
        oo2.myProfileSection(finding_index);
    }
}

void notifications :: go_for_notification(std::string name)
{
    std::string msg = "you try match with: " + name + " the " + current_time();
    notification.push_back(msg);
}

void notifications :: show_all_notifications()
{
    std::cout << "****************notifications*****************";
    if(notification.empty())
        std::cout << "nothing for now :]" << std::endl;
    else
        for(auto x : notification) 
            std::cout << x << std::endl;
    std::cout << "****************notifications*****************";
    main_menu();
}

social_media :: social_media()
{
    std::cout << "---------Social-Media-Accounts---------" << std::endl;
    std::cout << "instagram  " << "https://www.instagram.com/" << usernames[finding_index] << std::endl;
    std::cout << "twitter  " << '@' << usernames[finding_index] << std::endl;
    std::cout << "facebook  " << "https://www.facebook.com/" << usernames[finding_index] << std::endl;
    std::cout << "---------Social-Media-Accounts---------" << std::endl;
}

// ? main function:
int main ()
{
    clear_all_vectors();
    base();
}
