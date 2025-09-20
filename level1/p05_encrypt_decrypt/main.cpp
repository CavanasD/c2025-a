#include<iostream>
#include<string>
#include <iomanip> // 需要这个头文件来格式化输出
#include <sstream> // 需要这个头文件来进行字符串流操作
/***
 *                    _ooOoo_
 *                   o8888888o
 *                   88" . "88
 *                   (| -_- |)
 *                    O\ = /O
 *                ____/`---'\____
 *              .   ' \\| |// `.
 *               / \\||| : |||// \
 *             / _||||| -:- |||||- \
 *               | | \\\ - /// | |
 *             | \_| ''\---/'' | |
 *              \ .-\__ `-` ___/-. /
 *           ___`. .' /--.--\ `. . __
 *        ."" '< `.___\_<|>_/___.' >'"".
 *       | | : `- \`.;`\ _ /`;.`/ - ` : | |
 *         \ \ `-. \_ __\ /__ _/ .-` / /
 * ======`-.____`-.___\_____/___.-`____.-'======
 *                    `=---='
 *
 * .............................................
 *          佛祖保佑             永无BUG
 */
using namespace std;

string String_Origin;
string SecretKey;

string Encrypt() {
    string result_e = String_Origin;
    for (unsigned long long i = 0; i < String_Origin.length(); i++) {
        result_e[i] = String_Origin[i] ^ SecretKey[i % SecretKey.length()];
    }
    return result_e;
}

string Decrypt() {
    string result_d = Encrypt();
    return result_d;
}

string toHex(const string &str) {
    stringstream ss;
    ss << hex << setfill('0');
    for (unsigned char c: str) {
        ss << setw(2) << static_cast<int>(c);
    }
    return ss.str();
}

string fromHex(const string& hexStr) {
    string result = "";
    if (hexStr.length() % 2 != 0) {
        cout << "Error: Hex string  must have an even number of characters." << endl;
        string.length = result.length();
        return ""; // 返回空字符串表示失败
    }
    for (size_t i = 0; i < hexStr.length(); i += 2) {
        std::string byteString = hexStr.substr(i, 2);
        std::stringstream ss;
        ss << std::hex << byteString;
        int byteValue;
        ss >> byteValue;
        result += static_cast<char>(byteValue);
    }
    return result;
}

int main() {
    while (true) {
        cout << "******************************" << endl;
        cout << "Welcome to the Encrypt Tool" << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice" << endl;
        cout << "******************************" << endl;
        int choiceNum;
        cin >> choiceNum;
        if (choiceNum == 3) {
            cout << "Goodbye!" << endl;
            break;
        }
        switch (choiceNum) {
            case 1: {
                cout << "Enter your SecretKey" << endl;
                cin >> SecretKey;
                cout << "Enter the text that you want to encrypt" << endl;
                cin >> String_Origin;
                string result_ee = Encrypt();
                cout << "Here is it!" << endl;
                cout << toHex(result_ee) << endl;
                break;
            }
            case 2: {
                cout << "Enter your SecretKey" << endl;
                cin >> SecretKey;
                cout << "Enter the text that you want to decrypt" << endl;
                cin >> String_Origin;
                String_Origin = fromHex(String_Origin);
                string result_d = Decrypt();
                cout << "Here is it!" << endl;
                cout << result_d << endl;
                break;
            }
        }
        system("pause");
        system("cls");
    }
    return 0;
}
