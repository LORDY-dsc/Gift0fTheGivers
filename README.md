# Gift0fTheGivers
Crisis Aid Resource Engine is a C++ disaster relief management system designed to coordinate emergency aid distribution. It uses arrays, linked lists, binary search trees, stacks, and priority queues to manage inventory, process aid requests, track shipments, and prioritize critical disaster response operations.

# Crisis Aid Resource Engine

A C++ disaster relief management system designed to coordinate emergency aid distribution during natural disasters and humanitarian crises. The system manages relief requests, warehouse inventory, supply shipments, and prioritization of emergency responses using various data structures and algorithms.

## Features

- User authentication and role-based access control
- Disaster relief request management
- Warehouse inventory tracking
- Emergency request prioritization
- Shipment management and tracking
- File-based data persistence
- Input validation and error handling

## Data Structures Implemented

### Arrays
Used for warehouse inventory management:
- Store relief supplies and quantities
- Search and update inventory records
- Sort inventory using Bubble Sort

### Doubly Linked Lists
Used for shipment management:
- Track outgoing shipments
- Maintain shipment history
- Efficient traversal of records

### Binary Search Trees (BST)
Used for:
- Supply inventory organization
- Order management
- Fast searching and retrieval of records

### Priority Queue
Used for emergency aid requests:
- High-priority disasters are processed first
- Ensures efficient allocation of resources
- Supports critical response operations

### Stack
Used for:
- Storing processed requests
- Maintaining request history
- Supporting audit and tracking functionality

### Recursion
Demonstrates recursive programming concepts through system utility functions.

## Supported Disaster Types

- Floods
- Fires
- Earthquakes

## Supported Relief Supplies

- Water
- Food
- Medicine
- Clothes
- Blankets
- Tents
- Hygiene Kits

## Project Structure

```text
├── Login_Manager.h
├── Arrays_PartB.h
├── Binary_Search_Trees.h
├── Doubly_Linked_List.h
├── requests.txt
└── main.cpp
