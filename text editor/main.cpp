// از کاراکتر k برای شمارنده داخل حلقه ها استفاده شده

#include <iostream>


using namespace std;

int main() {
    // برای ذخیره کلمات به کار میرن
    string text[500];
    string words;
    char ch;
    //برای جایگذاری کلمات داخل ارایه
    int i=0;

    //شمارش کلمه و کاراکتر
    // متغیر w برای نشان دهنده خانه های پر شده آرایس
    int w=0;
    int totalWords=0;
    int c=0;
    int totalCharacter=0;

    // برای جمع اعداد
    int sum=0;

    // برای نمایش تعداد کاراکتر انتخاب شده
    char favChar;
    int totalFavChar=0;

    // برای نمایش کلمات کلیدی متن در بخش هفت متغیرهاش ساخته شده

    // منوی کاربری
    cout << "What is this text editor can do : " << endl;
    cout << "...................................................." << endl;
    cout << endl ;
    cout << "1. Correct the wrong to be verb ." << endl;
    cout << "2. Replacing dots with question mark in question sentence ." << endl;
    cout << "3. showing three most important word in the text ." << endl;
    cout << "4. Showing the number of usage of a favorite character ." << endl;
    cout << "5. Showing the number of the words ." << endl;
    cout << "6. Showing the number of characters ." << endl;
    cout << "7. Showing the the sum of the number that we used in our text ." << endl;
    cout << endl ;
    cout << "...................................................." << endl;
    cout << endl << endl;

    //بخش اول گرفتن کلمات از کاربر
    cout<< "Enter your text : "<<endl;
    while (true) {
        cin.get(ch);

        if (ch!=' ') {
            if (ch=='\n') {
                break;
            }else {
                words += ch;
                c++;
            }
        }else if (ch==' ') {
            text[i] = words;
            i++;
            w++;
            words.clear();
        }
    }
    //اضافه کردن کلمه اخر
    text[i] = words;
    /*درسته اخری همیشه کاراکتره اما چون تو بخش کم کردن کاراکتر ها
     *همه کاراکتر ها رو کم میکنم (یعنی حتی اخریشم) پس این باید شمرده شه
     */
    //به طرز عجیبی این نیاز نیست
    //w++;



    //بخش دوم درست کردم جمله کمکی
    for (int k=0;k<w;k++) {
        if ((text[k]=="I" || text[k]=="i") && (text[k+1]=="are")) {
            text[k+1]="am";
            c--;
        }
        if ((text[k]=="I" || text[k]=="i") && (text[k+1]=="is")) {
            text[k+1]="am";
        }
        if ((text[k]=="You" || text[k]=="you") && (text[k+1] =="am")) {
            text[k+1]="are";
            c++;
        }
        if ((text[k]=="You" || text[k]=="you") && (text[k+1] =="is")){
            text[k+1]="are";
            c++;
        }
        if ((text[k]=="He" || text[k]=="he") && (text[k+1] =="am")) {
            text[k+1]="is";
        }
        if ((text[k]=="He" || text[k]=="he") && (text[k+1] =="are")) {
            text[k+1]="is";
            c--;
        }
        if ((text[k]=="She" || text[k]=="she") && (text[k+1] =="am")){
            text[k+1]="is";
        }
        if ((text[k]=="She" || text[k]=="she") && (text[k+1] =="are")) {
            text[k+1]="is";
            c--;
        }
        if ((text[k]=="They" || text[k]=="they") && (text[k+1] =="am")) {
            text[k+1]="are";
            c++;
        }
        if ((text[k]=="They" || text[k]=="they") && (text[k+1] =="is")) {
            text[k+1]="are";
            c++;
        }
    }

    //بخش سوم قسمت اول سوالات بله یا خیر
    int j=1;
    while (j<w) {

        //اگه ضمایر فاعلی اول جمله نباشن پس جمله سوالیست
        if ((text[j]=="i" || text[j]=="you" || text[j]=="he" || text[j]=="she" || text[j]=="they" || text[j]=="this" ||text[j]=="that" || text [j]=="those" || text[j]=="these" ) &&
            ( text[j-1]=="do" || text[j-1]=="did" || text[j-1]=="am" || text[j-1]=="are" || text[j-1]=="is" || text[j-1]=="about" )) {
            for (int k=j;k<j+5;k++) {
                if (text[k]=="." || text[k]=="!") {
                    text[k]="?";
                    j=k;
                }else if (text[k]=="?") {
                    j=k;
                }else if (text[k]!="." || text[k]!="!" || text[k]!="?" ) {
                    w--;
                    w++;
                }
                if (text[k]=="." || text[k]=="!" || text[k]=="?") {
                    break;
                }
            }
        }
        j++;
    }


    /*
    // بخش سوم قسمت دوم wh سوالی ها
    j=1;
    while (j<w) {
        if (text[j]=="What" || text[j]=="Why" || text[j]=="Who" || text[j]=="Where" || text[j]=="When" || text[j]=="When") {
            for (int k=j;k<j+5 ;k++) {
                if (text[k]=="." || text[k]=="!") {
                    text[k]="?";
                    j=k;
                    break;
                }else if (text[k]=="?") {
                    j=k;
                    break;
                }
            }
        }
        j++;
    }
    */

    // بخش چهارم شمارش کلمات و کاراکترها
    totalWords=w;
    totalCharacter=c;
    for (int k=0;k<w;k++) {
       if (text[k]=="." || text[k]=="!" || text[k]=="?" || text[k]==",") {
           totalWords--;
           totalCharacter--;
       }
    }
    // همیشه یه کاراکتر کمتر نشون میداد نمیدونم چرا
    // اینم نیاز نیست
    // totalCharacter++;

    // بخش پنج جمع اعداد
    // کمک گرفته شده از StackOverflow
    for (const string& item : text) {
        if ( item[0] >= '0' && item[0] <= '9') {
            //تابعی برای تبدیل استرینگ به اینتجر
            sum += stoi(item);
            totalWords--;
            if (stoi(item) >=0  && stoi(item) <= 9) {
                totalCharacter--;
            }else if ( stoi(item) >= 10 && stoi(item) <= 99) {
                totalCharacter=totalCharacter-2;
            }else if ( stoi(item) >= 100 && stoi(item) <= 999) {
                totalCharacter=totalCharacter-3;
            }else if ( stoi(item) >= 1000 && stoi(item) <= 9999) {
                totalCharacter=totalCharacter-4;
            }else if ( stoi(item) >= 10000 && stoi(item) <= 99999) {
                totalCharacter=totalCharacter-5;
            }else if ( stoi(item) >= 100000 && stoi(item) <= 99999) {
                totalCharacter=totalCharacter-6;
            }
        }
    }


    // بخش شش نمایش تعداد کاراکتر انتخاب شده
    cout<< "Enter your character that you want to see : ";
    cout<<endl;
    cin >> favChar;
    cout<<endl;
    for (int k=0;k<w;k++) {
        // z برای گشتن حروف کلمس
        for (int z=0; z<10 ;z++) {
            if (text[k][z]==favChar ) {
                totalFavChar++;
            }else if (text[k][z]=='\0') {
                break;
            }
        }
    }



    // بخش هفت نمایش کلمات کلیدی متن
    // در این بخش از هوش مصنوعی کمک گرفته شده
    string importantWords[3];
    int countOfImportantWords[3]={0,0,0};
    for (int k=0;k<w;k++) {
        int count=1;
        if (text[k]!="." && text[k]!="!" && text[k]!="?" && text[k]!=",") {
            for (int z=k+1;z<w;z++) {
                if (text[k]==text[z]) {
                    count++;
                }
            }
            for (int m=0; m<3; m++) {
                if (count > countOfImportantWords[m]) {
                    for (int n=2 ; n>m ; n--) {
                        countOfImportantWords[n]=countOfImportantWords[n-1];
                        importantWords[n]==importantWords[n-1];
                    }
                    countOfImportantWords[m] = count;
                    importantWords[m] = text[k];
                    break;
                }
            }
        }
    }






    // بخش اخر نمایش کلمات
    for (int k=0 ; k<w ; k++) {
        cout<< text[k] << " " ;
    }
    cout << endl;
    cout << endl;
    cout <<  "The number of the words : " << totalWords<< endl;
    cout << endl;
    cout << "The number of the character is : " << totalCharacter<< endl;
    cout << endl;
    cout << "The total of the text numbers are : " << sum << endl;
    cout << endl;
    cout << "The number of repeat for " << favChar << " is : " << totalFavChar << endl;
    //نمایش کلمات مهم
    cout << endl;
    cout << "The most important words are : " << endl;
    cout << importantWords[0] << " Repeated " << countOfImportantWords[0] << " times" << endl;
    cout << importantWords[1] << " Repeated " << countOfImportantWords[1] << " times" << endl;
    cout << importantWords[2] << " Repeated " << countOfImportantWords[2] << " times" << endl;


    int system(const char *command);



    return 0;
}
