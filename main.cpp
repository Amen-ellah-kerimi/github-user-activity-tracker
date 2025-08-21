#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

// WriteCallback stays the same
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string fetchUserEvents(const string& username) {
    string url = "https://api.github.com/users/" + username + "/events";
    string response;
    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // GitHub requires User-Agent
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "User-Agent: MyCplusplusApp");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);

        if (res != CURLE_OK) {
            cerr << "Error: " << curl_easy_strerror(res) << endl;
        }
    }
    return response;
}

int main() {
    string username;
    cout << "Enter GitHub username: ";
    cin >> username;

    string response = fetchUserEvents(username);

    // Parse JSON
    try {
        json events = json::parse(response);

        cout << "\nRecent Events for " << username << ":\n";
        for (auto& ev : events) {
            string type = ev["type"];
            string repo = ev["repo"]["name"];
            cout << "- " << type << " on " << repo << endl;
        }
    } catch (json::parse_error& e) {
        cerr << "Failed to parse JSON: " << e.what() << endl;
    }

    return 0;
}

