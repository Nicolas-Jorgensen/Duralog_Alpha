// COMSC-210 - Nicolas Jorgensen
// Lab 29 - <Pseudocode for std::map-based fire sim>


// Include necessary headers for file handling, data structures, etc.

// Define a function to print current fire-state to console, flushing old console display
    // Parameters: map of fire tiles, current timestep

// Define a function to compute temp as a function of O2 and CO2
    // Parameters: map of fire tiles, current timestep

// Define a function to avg O2 levels across the fire
    // Parameters: map of fire tiles, current timestep

// Define a function to calculate higher tile's CO2 levels based on unfired CO2 from lower tiles
    // Parameters: map of fire tiles, current timestep

// Define main function
    // Initialize a map to store temps, O2 levels, and CO2 levels of each tile
    //initialize an int to account for current Timestep

    // Open an external file to read data for O2 and CO2 levels
        // If file does not open, print an error and exit

    // Read data from file and populate map
        // First extract O2 data
        // then extract CO2 data
        // Insert O2 and CO2 levels into appropriate lists in the map's value array
    // Close the file

    //Print fancy Header

    // Begin a time-based simulation for DuraLog Fire
        // For 100 time intervals
            // Call function to avg O2 across fire
            // Call function to calc each tile's CO2
            // Call function to calculate temp
            //call function to print all fire tiles
            // advance Timestep
    //Continue loop              
// End of main function