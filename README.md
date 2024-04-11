# CS210-ProgrammingLanguages
A collection of the major work I accomplished in this title course at Southern New Hampshire University (SNHU).

See below for my thoughts on Project One ("12- and 24-hour Clock"). I chose to write about this one because it was a journey!
  -

"Summarize the project and what problem it was solving."
  - The objective of the project was to display accurate 12- and 24-hour clock displays to the user, based on their input of time in either 12- or 24-hour format. Beyond the initial input, the user has the continuous options of incrementing the seconds, minutes, and hours by 1. These actions repeat until the user is finished and enters a sentinel value. Although this was the first project, and the clocks neither tick in real-time nor does the program completely validate input, it was the first time I was tasked with creating a class in C++.
    
"What did you do particularly well?"
  - I persevered and built a class despite feeling nervous about messing up. I also found a clever way to ensure the 12-hour time is always accurate to AM/PM specifications using only the 24-hour time as a guide. At first, I attempted to read "AM" or "PM" from input, then I tried appending it to the 12-hour time and changing it based on the hour, but I ran into input/output problems and an issue with midnight not registering as AM and noon not registering as PM. It was a headache with no clear way out! After some time away from the project, I considered determining the 12-hour time solely based on the 24-hour time, and it was the answer I'd been looking for all along. Instead of trying to find some convoluted way to get the program to recognize midnight versus noon, the program simply looks to whether the 24-hour time is 12:00 (noon) or 00:00 (midnight).
    
"Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?"
  - There is a repetitive part of my code that could be made into a separate function-- the part that determines whether the 12-hour time is in AM/PM format based on the 24-hour time. To ensure this is always working, I have it repeated in each add...() function, but this is redundant and I would modularize that better now.
    
"Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?"
  - Because I felt compelled to use classes for this project, and because we hadn't yet learned about C++ classes in our coursework, I felt particularly overwhelmed with the work. I'd written classes in Java in the previous term, but trying to figure out how to do it in C++ ahead of my coursework felt like a lot at once. I overcame it by working in increments and splitting the work up into "information gathering sessions", meaning that I spent a lot of time preparing for the work to ease my fear of incorrectly completing it. I asked questions of my search engine and found answers in online documentation and Stack Overflow. I looked ahead in my coursework to find examples of how classes looked straight from the textbook. Now that I've learned more about classes, they don't feel so intimidating, and I would've written my code for Project One a little differently (although it fulfills the project just fine). From this experience, I've added the aforementioned online resources to my support network, and I know that referencing my textbooks and notes is always helpful.
    
"What skills from this project will be particularly transferable to other projects or course work?"
  -

"How did you make this program maintainable, readable, and adaptable?"
  -
