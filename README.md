***

# Desi Library Management System

*"Because remembering who took which book is too mainstream."*
<br>
  

***

## **Project Objective**

*Target: 100/100 Marks (Zero negotiation).*

**Core Purpose:** This isn't just another library system; it's a feature-packed management tool built in C, designed to handle everything from cataloging and transactions to fines and reservations. The desi, informal vibe is intentional, making it more relatable for students while packing a professional punch under the hood.

**Real-world Context:** Libraries are messy. Students forget to return books. Librarians lose their minds. **We fixed it.** This system brings order to the chaos.

***

## **Key Features (The "The most AWAITED" Part)**

This isn't your basic CRUD app. We went all out with features you'd actually want in a real library system.

*   **Secure Login:** A simple password system to keep random people from messing with the records.
*   **Full Inventory Control (`godam.c`):**
    *   **Add, Edit, Delete:** Full control over the book catalog.
    *   **Duplicate ID Check:** Prevents adding two books with the same ID.
    *   **Safe Deletion:** Won't let you delete a book that a student currently has.
*   **Transaction Management (`len_den.c`):**
    *   **Issue & Return:** Smoothly handles giving and taking back books.
    *   **Fine Calculation:** Automatically calculates fines for late returns (`Rs. 10/day` after 15 days!).
    *   **Reservation System:** If a book is issued, another student can get in the waitlist.
*   **Persistent Data (`helper.c`):**
    *   **Auto Save & Load:** All book and transaction data is saved to `library_data.txt`. No more data loss when you close the app!
*   **Advanced Search Engine (`helper.c`):**
    *   Finds books by **Title, Author, or Genre** with partial matches (e.g., "Harry" finds "Harry Potter").
*   **Analytics & Reports (`helper.c`):**
    *   Get a quick "Report Card" of the library: total books, issued books, available stock, and total fines collected.
*   📜 **Complete Audit Trail (`helper.c`):**
    *   Logs every **ISSUE** and **RETURN** action with a timestamp. Perfect for tracking who did what, and when.

***

## **The "Dream Team" (Credits)**

Built with lots of caffeine ☕ and 💻 many late nights debugging by:

*   **Ankan** - Backend Logic, File I/O & Pointer Wizardry
*   **Protistha** - Database Structure & Variable Schemas
*   **Shivansh** - Search/Sort Algorithms & Bug Hunting
*   **Aditya** - Documentation & Viva Defense Squad

***

## **How to Compile & Run (Don't mess this up)**

Since we used **Modular Programming** (fancy, right?), you can't just hit "Run" on `main.c`. You have to link all the `.c` files together into one executable.

**Step 1: Open Terminal**

Go to the folder where you dumped our code.

**Step 2: Compile**

Type this magic spell into your terminal. This command tells the GCC compiler to take all our source files and create a single output program named `library_app`.

```bash
gcc main.c godam.c len_den.c helper.c -o library_app
```

**Step 3: Run**

Launch the beast:

```bash
./library_app
```

***

## **Usage Guide (How the Magic Works)**

### 1. The Login & Main Menu
First, you'll be greeted by a security check. Once you're in, the powerful main menu appears.

```
=== MAIN MENU (PRO MAX) ===
1. Stock Dekho (List)
2. Nayi Kitab Add Karo
3. Kitab Issue Karo
4. Kitab Return Karo
5. Waitlist/Reservation
6. Search (Khoj)
7. Reports & Stats
8. History Log (Audit)
9. Edit/Sort/Delete (Admin Tools)
10. Save & Exit (Tata Bye Bye)
Choice batao: _
```

### 2. Adding a Book (`godam.c` in action)
Safely add a book with duplicate ID prevention. 
```
--- Nayi Kitab Entry (Dhyan se bharna) ---
ID batao (Unique honi chahiye): 106
Kitab ka naam: The Psychology of Money
Lekhak (Author): Morgan Housel
Genre (e.g. Horror/Code): Finance
Keemat (Price in Rs): 350
>> Badhai ho! Kitab 'The Psychology of Money' register ho gayi.
```

### 3. Issuing a Book & History Log (`len_den.c` + `helper.c`)
When a book is issued, a timestamped entry is automatically added to the history log.

```
--- ISSUE COUNTER ---
Kaunsi Kitab (ID): 106
Student ka naam: Protistha
Aaj ki Date (DD/MM/YYYY): 01/12/2025
>> Issued! Protistha, isko phadna mat please.

...
// Later, checking the history log (Option 8)
--- LOG BOOK (Kaun kab kya le gaya) ---
[Mon Dec 01 21:15:00 2025] ID:106 | User:Protistha | Action:ISSUE
```

### 4. Returning a Book with Fine Calculation
If a student is late, the system automatically calculates the fine.

```
--- RETURN & FINE COUNTER ---
Kitab ID wapas aayi: 106
Kitne din rakhi thi (Sach bolna): 20
>> LATE ENTRY! 15 din allowed the.
>> 5 din late ho. Total Fine: Rs 50
>> Fine diya? (1=Haan/0=Nahi): 1
>> Kitab wapas shelf pe rakh di gayi hai.
```

### 5. Getting a Report Card
Instantly see the library's current status. Great for a quick overview.

```
--- LIBRARY ANALYTICS (Viva stats) ---
Total Books:     15
Books Issued:    4 (Padaku log)
Books in Godam:  11
Total Fine:      Rs 50 (Chai-sutta budget)
Total Txns:      9
--------------------------------------
```

***

> ## System.out.println("Thank you for checking out our project - Ankan");
