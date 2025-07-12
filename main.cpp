// Standard input/output for console operations
#include <iostream>
// Windows API for console handling and multimedia functions
#include <Windows.h>
// Console input handling for non-blocking keyboard input
#include <conio.h>
// Multimedia control interface for audio playback
#include <mmsystem.h>
// String manipulation and handling
#include <string>
// Formatting output (e.g., setw for aligned text)
#include <iomanip>
// Vector container for storing song data
#include <vector>
// Limits for input buffer clearing
#include <limits>

using namespace std;

// OOP Pillar: Encapsulation - ConsoleDisplay class bundles console output functionality
// and restricts direct access to console handle and color-setting logic
class ConsoleDisplay {
private:
    // OOP Pillar: Encapsulation - Private member 'hConsole' restricts direct access to console handle
    HANDLE hConsole;

    // OOP Pillar: Encapsulation - Private method to control console color changes internally
    void setConsoleColor(WORD color) {
        SetConsoleTextAttribute(hConsole, color);
    }

public:
    // Constructor: Initializes the console handle
    ConsoleDisplay() {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    // OOP Pillar: Abstraction - displayProjectInfo provides a simplified interface for
    // displaying formatted project info, hiding Windows API and formatting details
    void displayProjectInfo() {
        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\n";
        cout << "\t\t\t============================================================\n";
        cout << "\t\t\t|                                                          |\n";
        cout << "\t\t\t|           *** MelodyMaster Music Player ***              |\n";
        cout << "\t\t\t|      Interactive Console-Based Audio Experience          |\n";
        cout << "\t\t\t|                                                          |\n";
        cout << "\t\t\t============================================================\n";
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        cout << "\n";
        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\t\tWelcome to MelodyMaster!\n";
        cout << "\t\tA console-based music player built with C++.\n";
        cout << "\t\tPlay, pause, resume, stop, forward & backward(10 sec) your favorite songs or nausheeds.\n";
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        cout << "\n";
        cout << left;
         setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\t\t" << string(90, '-') << "\n";
        cout << "\t\t" << setw(50) << "Group Members" << "Social Media" << endl;
        cout << "\t\t" << string(90, '-') << "\n";
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        vector<pair<string, string>> members = {
            {"** @Loofy_Guy (Abdul Rafay Siddiqui - 065)", "IG: loofy_guy\n\t\thttps://www.instagram.com/loofy_guy/"},
       //     {"** @muhammad_haris_alii(Muhammad Haris Ali - 064)", "IG: muhammad_haris_alii\n\t\thttps://www.instagram.com/muhammad_haris_alii/"},
           // {"** @ainazubair119 (Qurrat Ul Ain Zubair - 085)", "IG: ainazubair119\n\t\thttps://www.instagram.com/ainazubair119/"},
            //{"** @aisha_laeeque (Aisha Laique - 053)", "IG: aisha_laeeque\n\t\thttps://www.instagram.com/aisha_laeeque/"}
        };

        for (const auto& member : members) {
            cout << "\t\t" << setw(50) << member.first << member.second << endl << endl;
        }

        cout << "\t\t" << string(90, '-') << "\n\n";
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    // OOP Pillar: Abstraction - displayControls provides a simple interface for
    // showing control instructions, hiding output formatting details
    void displayControls() {
        cout << "Press 'p' to Play" << endl;
        cout << "Press 'p' to Pause" << endl;
        cout << "Press 'r' to Resume" << endl;
        cout << "Press 's' to Stop" << endl;
        cout << "Press 'j' to Rewind 10 seconds" << endl;
        cout << "Press 'k' to Forward 10 seconds" << endl;
        cout << "Press 'q' to Quit" << endl;
    }
};

// OOP Pillar: Encapsulation - SongManager class bundles song/nausheed data and selection logic
// and restricts direct access to song lists
class SongManager {
private:
    // OOP Pillar: Encapsulation - Private songList and nausheedList protect data
    // from direct external access
    vector<pair<string, string>> songList = {
        {"Pal Pal Afusic", "PalPalAfusic.wav"},
        {"Whistle Joyride", "whistlejoyride.wav"},
        {"Tere Naino Mein", "Terenainomain.wav"},
        {"Lal Timatar Bade Mazaydaar", "Laltimatarbademazaydaar.wav"},
        {"Love Me Like You Do", "Lovemelikeyoudo.wav"},
        {"Amplifier", "Amplifier.wav"},
        {"Surili Akhiyon Wale", "Suriliakhiyonwale.wav"},
        {"Shikayat", "Shikayat.wav"},
        {"All My Friends Are Toxic", "Allmyfriendsaretoxic.wav"},
        {"Aleemrk-Cold Hours", "Aleemrk-Coldhours.wav"},
        {"Millionaire", "Millionaire.wav"},
        {"Ishq", "Ishq.wav"},
        {"Raabta", "Raabta.wav"},
        {"Tum Mile Jaadu", "tum_mile_jaadu.wav"},
        {"Kabhi Na Kabhi To Miloge", "kabhi_na_kabhi_to_miloge.wav"},
        {"Kabhi Jo Badal Barse", "kabhi_jo_badal_barse.wav"},
        {"Humraah", "humraah.wav"},
        {"Hui Malang", "hui_malang.wav"},
        {"Humnava", "Humnava.wav"},
        {"Chaand Baaliyaan", "chaand_baaliyan.wav"},
        {"Jo Tum Mere Ho", "Jo_tum_mere_ho.wav"},
        {"Aye Khuda", "Aye_khuda.wav"}
    };

    vector<pair<string, string>> nausheedList = {
        {"Ashrakat-Nafsi", "Ashrakat-Nafsi.wav"},
        {"Kun Faya Kun", "Kun_Faya_Kun.wav"},
        {"Lab-Pe-Aati-Hai-Dua-Banke-Tamanna-Meri", "Lab-Pe-Aati-Hai-Dua-Banke-Tamanna-Meri.wav"},
        {"Give-Thanks-To-Allah", "Give-Thanks-To-Allah.wav"},
        {"Habibi-Ya-Muhammad", "Habibi-Ya-Muhammad.wav"},
        {"Hasbi-Rabbi-Live-in-New-Delhi", "Hasbi-Rabbi-Live-in-New-Delhi.wav"},
        {"maula-ya-salli-wa-sallim", "maula-ya-salli-wa-sallim.wav"},
        {"mawlaya", "mawlaya.wav"},
        {"Muhammad-Nabina", "Muhammad-Nabina.wav"},
        {"Wedding", "Wedding.wav"},
        {"Yanabi_salam_alik", "Yanabi_salam_alik.wav"},
        {"Ya-Nabi-SAW", "Ya-Nabi-SAW.wav"}
    };

public:
    // OOP Pillar: Abstraction - chooseCategory simplifies category selection,
    // hiding input validation and list management details
    char chooseCategory() {
        cout << "Select a category:\n";
        cout << "1: Songs\n";
        cout << "2: Nausheeds\n";
        cout << "Enter your choice (1 or 2): ";

        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (choice != '1' && choice != '2') {
            cout << "Invalid choice. Please select 1 or 2." << endl;
            return '\0'; // Invalid choice
        }
        return choice;
    }

    // OOP Pillar: Abstraction - chooseSong provides a simple interface for track selection,
    // hiding list iteration and validation logic
    string chooseSong(char category) {
        vector<pair<string, string>>* selectedList = (category == '1') ? &songList : &nausheedList;
        string categoryName = (category == '1') ? "Songs" : "Nausheeds";

        if (selectedList->empty()) {
            cout << "No " << categoryName << " available." << endl;
            return "";
        }

        cout << "Choose a " << categoryName << " to play:\n";
        for (size_t i = 0; i < selectedList->size(); ++i) {
            cout << i + 1 << ": " << (*selectedList)[i].first << endl;
        }
        cout << endl << "Enter the number of the " << categoryName << " you want to play: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            return "";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (choice < 1 || choice > static_cast<int>(selectedList->size())) {
            cout << "Invalid choice. Please select a number between 1 and " << selectedList->size() << "." << endl;
            return "";
        }

        return (*selectedList)[choice - 1].second;
    }
};

// OOP Pillar: Encapsulation - MusicPlayer class bundles playback state and logic,
// restricting direct access to track state and MCI commands
class MusicPlayer {
private:
    // OOP Pillar: Encapsulation - Private members to track player state, inaccessible directly
    bool isPlaying;
    bool isPaused;
    string currentTrack;

    // OOP Pillar: Encapsulation - Private method to execute MCI commands, hiding low-level details
    bool executeMCICommand(const string& command, char* buffer = nullptr, size_t bufferSize = 0) {
        DWORD result = mciSendStringA(command.c_str(), buffer, bufferSize, NULL);
        if (result != 0) {
            char error[128];
            mciGetErrorStringA(result, error, sizeof(error));
            cout << "MCI Error: " << error << " (Command: " << command << ")" << endl;
            return false;
        }
        return true;
    }

    // OOP Pillar: Encapsulation - Private method to check track state, used internally
    bool isTrackPlayable() {
        char buffer[128];
        if (!executeMCICommand("status currentTrack mode", buffer, sizeof(buffer))) {
            return false;
        }
        return (strcmp(buffer, "playing") == 0 || strcmp(buffer, "paused") == 0);
    }

    // OOP Pillar: Encapsulation - Private method to handle track playback, hiding MCI details
    bool playTrack(const string& track) {
        if (isTrackPlayable()) {
            executeMCICommand("close currentTrack");
        }
        string command = "open \"" + track + "\" type waveaudio alias currentTrack";
        if (!executeMCICommand(command)) {
            isPlaying = false;
            isPaused = false;
            return false;
        }
        if (!executeMCICommand("play currentTrack")) {
            executeMCICommand("close currentTrack");
            isPlaying = false;
            isPaused = false;
            return false;
        }
        isPlaying = true;
        isPaused = false;
        currentTrack = track;
        cout << "Playing " << track << "..." << endl;
        return true;
    }

    // OOP Pillar: Encapsulation - Private method to pause track, controlling state internally
    bool pauseTrack() {
        if (!isPlaying || isPaused) {
            cout << "Cannot pause: Track is not playing." << endl;
            return false;
        }
        if (!isTrackPlayable()) {
            cout << "Cannot pause: Track is not in a playable state." << endl;
            return false;
        }
        if (executeMCICommand("pause currentTrack")) {
            isPaused = true;
            isPlaying = false;
            cout << "Paused." << endl;
            return true;
        }
        return false;
    }

    // OOP Pillar: Encapsulation - Private method to resume track, controlling state internally
    bool resumeTrack() {
        if (!isPaused) {
            cout << "Cannot resume: Track is not paused." << endl;
            return false;
        }
        if (!isTrackPlayable()) {
            cout << "Cannot resume: Track is not in a playable state." << endl;
            return false;
        }
        if (executeMCICommand("resume currentTrack")) {
            isPaused = false;
            isPlaying = true;
            cout << "Resumed..." << endl;
            return true;
        }
        return false;
    }

    // OOP Pillar: Encapsulation - Private method to stop track, controlling state internally
    bool stopTrack() {
        if (!isTrackPlayable()) {
            isPlaying = false;
            isPaused = false;
            currentTrack = "";
            return true;
        }
        if (executeMCICommand("stop currentTrack") && executeMCICommand("close currentTrack")) {
            isPlaying = false;
            isPaused = false;
            currentTrack = "";
            cout << "Stopped." << endl;
            return true;
        }
        return false;
    }

    // OOP Pillar: Encapsulation - Private method to seek in track, hiding MCI command details
    bool seek(int milliseconds) {
        if (!isTrackPlayable()) {
            cout << "Cannot seek: Track is not in a playable state." << endl;
            return false;
        }
        char buffer[128];
        if (!executeMCICommand("status currentTrack position", buffer, sizeof(buffer))) {
            return false;
        }
        int currentPosition = atoi(buffer);
        int newPosition = max(0, currentPosition + milliseconds);
        char seekCommand[128];
        sprintf_s(seekCommand, sizeof(seekCommand), "seek currentTrack to %d", newPosition);
        if (executeMCICommand(seekCommand)) {
            if (isPlaying) {
                executeMCICommand("play currentTrack");
            }
            cout << (milliseconds < 0 ? "Rewound 10 seconds." : "Forwarded 10 seconds.") << endl;
            return true;
        }
        return false;
    }

public:
    // Constructor: Initializes player state
    MusicPlayer() : isPlaying(false), isPaused(false), currentTrack("") {}

    // OOP Pillar: Abstraction - handleInput provides a simple interface for controlling
    // playback, hiding complex state management and MCI command execution
    void handleInput(char ch, ConsoleDisplay& display) {
        switch (tolower(ch)) { // Case-insensitive input
            case 'p': // Play or Pause track
                if (!isPlaying && !isPaused && !currentTrack.empty()) {
                    playTrack(currentTrack);
                } else if (isPlaying && !isPaused) {
                    pauseTrack();
                }
                break;
            case 'r': // Resume track
                if (isPaused) {
                    resumeTrack();
                }
                break;
            case 's': // Stop track
                if (isPlaying || isPaused) {
                    stopTrack();
                }
                break;
            case 'j': // Rewind 10 seconds
                if (isPlaying || isPaused) {
                    seek(-10000);
                }
                break;
            case 'k': // Forward 10 seconds
                if (isPlaying || isPaused) {
                    seek(10000);
                }
                break;
            case 'q': // Quit current track
                if (isPlaying || isPaused) {
                    stopTrack();
                }
                currentTrack = "";
                break;
        }
    }

    // OOP Pillar: Abstraction - isTrackActive provides a simple way to check track state,
    // hiding internal state details
    bool isTrackActive() const { return isPlaying || isPaused; }

    // OOP Pillar: Abstraction - setCurrentTrack allows setting the track, hiding internal state management
    void setCurrentTrack(const string& track) { currentTrack = track; }

    // OOP Pillar: Abstraction - getCurrentTrack provides access to current track, hiding internal details
    string getCurrentTrack() const { return currentTrack; }
};

// Main function: Entry point of the program
int main() {
    // Initialize display, song manager, and player objects
    ConsoleDisplay display;
    SongManager songManager;
    MusicPlayer player;

    // Display project information
    display.displayProjectInfo();

    bool isRunning = true; // Controls main program loop
    while (isRunning) {
        // Get user category selection (Songs or Nausheeds)
        char category = songManager.chooseCategory();
        if (category == '\0') {
            cout << "No valid category selected. Exiting..." << endl;
            break;
        }

        // Get user track selection
        string selectedTrack = songManager.chooseSong(category);
        if (selectedTrack.empty()) {
            cout << "No valid track selected. Exiting..." << endl;
            break;
        }

        // Set the selected track in the player
        player.setCurrentTrack(selectedTrack);
        // Display control instructions
        display.displayControls();

        bool isUserActive = true; // Controls track playback loop
        while (isUserActive) {
            if (_kbhit()) { // Check for keyboard input
                char ch = _getch(); // Get key press
                if (tolower(ch) == 'q') {
                    isUserActive = false; // Exit playback loop
                }
                player.handleInput(ch, display); // Process user input
            }
            Sleep(100); // Reduce CPU usage
        }

        // Ask if user wants to play another track
        char userChoice;
        cout << "Do you want to play another track? (y/n): ";
        cin >> userChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (tolower(userChoice) == 'n') {
            isRunning = false; // Exit program
        } else if (tolower(userChoice) == 'y') {
            if (player.isTrackActive()) {
                player.handleInput('s', display); // Stop current track
            }
        } else {
            cout << "Invalid choice. Exiting..." << endl;
            isRunning = false; // Exit on invalid input
        }
    }

    return 0; // Exit program
}
