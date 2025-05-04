#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

const string API_KEY = "Your Github Token"; //Github API Token
const string API_URL = "https://models.github.ai/inference/chat/completions";  


int get_model_selection() {
    int model_ai;
    cout << "Which AI model would you like to use: 1-Phi-4, 2-Meta, 3-ChatGpt: ";
    cin >> model_ai;
    cin.ignore();  
    return model_ai;
}

int main() {
    int model_ai = get_model_selection();  
    string user_input;
    json request_body;

    while (true) {
        cout << "Question: ";
        getline(cin, user_input);

        if (user_input == "exit") {
            cout << "Exiting...\n";
            break;
        }

        if (user_input == "change") {
            model_ai = get_model_selection();
            continue;
        }

        
        if (model_ai == 3) {
            request_body = {
                {"messages", json::array({
                    {{"role", "user"}, {"content", user_input}}
                })},
                {"model", "openai/gpt-4o"},
                {"max_tokens", 4096},
                {"temperature", 1},
                {"top_p", 1}
            };
        }
        else if (model_ai == 1) {
            request_body = {
                {"messages", json::array({
                    {{"role", "user"}, {"content", user_input}}
                })},
                {"model", "microsoft/Phi-4"},
                {"temperature", 0.8},
                { "max_tokens", 2048 },
                {"top_p", 0.1}
            };
        }
        else if (model_ai == 2) {
            request_body = {
                {"messages", json::array({
                    {{"role", "user"}, {"content", user_input}}
                })},
                {"model", "Meta-Llama-3-8B-Instruct"},
                {"publisher", "Meta"},  
                {"temperature", 0.8},
                {"max_tokens", 2048},
                {"top_p", 0.1}
            };
        }
        else {
            cout << "Invalid Model!" << endl;
            break;
        }

        
        cpr::Response r = cpr::Post(
            cpr::Url{ API_URL },
            cpr::Header{
                {"Authorization", "Bearer " + API_KEY},  
                {"Content-Type", "application/json"}
            },
            cpr::Body{ request_body.dump() }  
        );

        if (r.status_code == 200) {
            json response_json = json::parse(r.text);
            string reply = response_json["choices"][0]["message"]["content"];
            cout << "Answer: " << reply << endl;
        }
        else {
            cerr << "Error: " << r.status_code << " - " << r.text << endl;
        }
    }

    return 0;
}
