#include <bits/stdc++.h>
using namespace std;

class eBill {

    int cid = 0;
    float units = 0;
    float charges = 0;
    float charges_with_gst = 0;

    void calculation() {
        if (units <= 100) {
            charges = units * 1.5;
        }
        else if (units <= 300) {
            charges = (units - 100) * 3.5 + 150;
        }
        else if (units <= 600) {
            charges = (units - 300) * 4.5 + 700 + 150;
        }
        else {
            charges = (units - 600) * 6.75 + 1350 + 700 + 150;
        }

        charges_with_gst = charges + charges * 0.12;

        total_units += units;
        total_charges += charges;
        total_gst += charges * 0.12;
        final_charges += charges_with_gst;
        count++;
    }

public:
    static float total_units;
    static float total_charges;
    static float total_gst;
    static float final_charges;
    static int count;

    void user_input() {
        cout << "ENTER CONSUMER ID: ";
        cin >> cid;

        cout << "ENTER UNITS CONSUMED: ";
        cin >> units;

        calculation();
    }

    void bill_output() {
        cout << left << fixed << setprecision(2)
             << setw(12) << cid
             << setw(15) << units
             << setw(15) << charges
             << setw(15) << charges * 0.12
             << setw(15) << charges_with_gst
             << endl;
    }
};

// Static initialization
float eBill::total_units = 0;
float eBill::total_charges = 0;
float eBill::total_gst = 0;
float eBill::final_charges = 0;
int eBill::count = 0;

int main() {

    int n;
    cout << "ENTER NUMBER OF ENTRIES: ";
    cin >> n;

    vector<eBill> bills(n);

    // Input first
    for (int i = 0; i < n; i++) {
        cout << "\n--- Entry " << i + 1 << " ---\n";
        bills[i].user_input();
    }

    // Output
    cout << "\n================ BILL DETAILS ================\n\n";

    cout << "--------------------------------------------------------------------------\n";
    cout << left
         << setw(12) << "Cust_Id"
         << setw(15) << "Units"
         << setw(15) << "Charges"
         << setw(15) << "GST"
         << setw(15) << "Final Bill" << endl;
    cout << "--------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        bills[i].bill_output();
    }

    cout << "--------------------------------------------------------------------------\n";

    // Summary
    cout << fixed << setprecision(2);
    cout << "\nTOTAL CHARGES: " << eBill::total_charges;
    cout << "\nTOTAL GST: " << eBill::total_gst;
    cout << "\nFINAL BILL: " << eBill::final_charges;

    if (eBill::count > 0)
        cout << "\nAVERAGE UNITS: " << eBill::total_units / eBill::count;

    cout << endl;

    return 0;
}
