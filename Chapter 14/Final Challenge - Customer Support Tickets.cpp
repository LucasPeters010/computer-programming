// FINAL CHALLENGE - Customer Support Tickets (HARD)
// Combines classes, linked nodes, pointers, new/delete, streams and exceptions.
//
// Scenario: customers submit support tickets. Your system manages a stack:
// the most recently added ticket is handled first (LIFO).
//
// Tasks:
// A. Finish the Ticket class (getId/getTitle).
// B. parseTicket(line): use istringstream to read an integer ID and the
//    rest of the line as a title. Reject bad input with invalid_argument.
//    Sample line: "12 Printer is broken"
// C. TicketStack::push: allocate a Node and link it to the old head.
// D. TicketStack::top: return the latest Ticket (or throw if empty).
// E. TicketStack::pop: delete exactly one node (or throw if empty).
// F. Destructor: remove all remaining nodes.
// G. formatTicket: use ostringstream to return "#12: Printer is broken".
//
// Expected output after completing the tasks:
// #12: Printer is broken
// #11: Cannot log in
// Error: Stack is empty
//
// Hints: You may refer back to Linked Stack and both Streams exercises.
// Try each TODO separately. Do not implement everything at once.

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class Ticket {
public:
    Ticket(int newId, std::string newTitle)
        : id(newId), title(newTitle) {}

    int getId() const {
        // TODO A1: return id
        return id;
    }

    std::string getTitle() const {
        // TODO A2: return title
        return title;
    }

private:
    int id;
    std::string title;
};

Ticket parseTicket(const std::string& line) {
    std::istringstream input(line);
    int id = 0;
    std::string title;

    // TODO B1: extract id, throw std::invalid_argument if parsing fails

    input >> id;

    std::getline(input, title);

    if(title == ""){
        throw std::invalid_argument("The ticket can not be empty");
    }
    

    // TODO B2: read the rest of the line as title using std::getline
    // TODO B3: reject an empty title, then return a Ticket
    return Ticket(id, title); // Placeholder: add checks first
}

std::string formatTicket(const Ticket& ticket) {
    std::ostringstream output;
    // TODO G: compose "#ID: TITLE" using getters

    output << "#" << ticket.getId() << ": " << ticket.getTitle();
    return output.str();
}

class TicketStack {
private:
    class Node {
    public:
        Node(const Ticket& newTicket)
            : ticket(newTicket), next(nullptr) {}
        Ticket ticket;
        Node* next;
    };

    Node* head;

public:
    TicketStack() : head(nullptr) {}

    ~TicketStack() {
        // TODO F: release all nodes; reuse pop()
        while (!empty())
        {
            pop();
            /* code */
        }
        
    }

    bool empty() const { return head == nullptr; }

    void push(const Ticket& ticket) {
        // TODO C: allocate Node, link new node to previous head, update head
        Node* ticketNode = new Node(ticket);
        ticketNode->next = head;
        head = ticketNode;
    }

    Ticket top() const {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        // TODO D: return the Ticket stored in head
        return head->ticket;
    }

    void pop() {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        // TODO E: save old head, advance head, delete old head
    }
};

int main() {
    TicketStack tickets;

    try {
        tickets.push(parseTicket("11 Cannot log in"));
        tickets.push(parseTicket("12 Printer is broken"));

        std::cout << formatTicket(tickets.top()) << '\n';
        tickets.pop();
        std::cout << formatTicket(tickets.top()) << '\n';
        tickets.pop();

        // This should throw; catch it below.
        tickets.pop();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
