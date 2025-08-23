# GitHub User Activity (C++)

[![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![GitHub](https://img.shields.io/badge/GitHub-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/)
[![libcurl](https://img.shields.io/badge/libcurl-005680?style=for-the-badge)](https://curl.se/libcurl/)
[![JSON](https://img.shields.io/badge/nlohmann_json-000000?style=for-the-badge)](https://github.com/nlohmann/json)

A simple C++ command-line application that fetches and displays the recent public activity of a GitHub user using the GitHub REST API.

---

## 📌 Features
- Fetches recent public events for any GitHub user.
- Displays event type and repository name.
- Uses:
  - [libcurl](https://curl.se/libcurl/) for HTTP requests
  - [nlohmann/json](https://github.com/nlohmann/json) for JSON parsing

---

## ⚙️ Requirements
- C++17 or later
- [libcurl](https://curl.se/libcurl/) installed
- [nlohmann/json](https://github.com/nlohmann/json) (header-only)

On Ubuntu/Debian:
```bash
sudo apt-get install libcurl4-openssl-dev
```

Download nlohmann/json.hpp:
```bash
wget https://github.com/nlohmann/json/releases/latest/download/json.hpp -O json.hpp
```
Place json.hpp in your project directory or include path.

## 🚀 Build & Run

Compile:
```bash
g++ main.cpp -o github_user_activity -lcurl -std=c++17
```

Run:
```bash
./github_user_activity
```

### Example:

Enter GitHub username: torvalds

Recent Events for torvalds:
- PushEvent on torvalds/linux
- IssuesEvent on torvalds/subsurface

## ⚠️ Notes

Only public events are accessible via the API.

GitHub API has rate limits (60 requests/hour without authentication).

For higher limits, you can extend the code to use a personal access token.

