# CPTR 141: Project #2

## Problem Overview
Our second project deals with the field of education.  In education, the reading level of a particular resource is very important.  Teachers need to make sure that the books or assignments they give their students are *reader-friendly*.  That means, the language used needs to be easily understood by students at the intended grade level.  There is a big difference between the writing style of a high-school textbook and that of a second grade reader.  This idea of determining how easy a particular passage of text is to read is called measuring its [*readability*](https://en.wikipedia.org/wiki/Readability).

Readability is also important outside of education.  In fact, one of the most important [*soft skills*](https://en.wikipedia.org/wiki/Soft_skills) sought by employers is the ability to communicate clearly and effectively, both orally and in writing.   After all, if people can't easily read something, they are likely to ignore or miss-understand it.  Whether authoring a textbook, giving instructions for a computer program, or writing a marketing blurb for a website, readability matters!

![Readability](https://www.tckpublishing.com/wp-content/uploads/2016/04/Readability-1-1030x749.png)

The concept of readability became popular in the 1920's, and since then  many different readability formulas have been introduced. These formulas are simple enough that a computer program can analyze a writing sample and compute a score to measure how readable it is.  Your task in this project is to write a program that can analyze a passage of text and compute several different measures of its readability.

There are several basic measures of readability that can be easily computed.  They include:

* The average length of a sentence in words.
* The average word length (in syllables)
* The percent of sentences that are overly long.

There are also several more complex readability formulas that combine these measures, or others, into a single number.  These *readability indexes* include:

* The [Automated readability index](https://en.wikipedia.org/wiki/Automated_readability_index)
* The [Flesch-Kincaid readability tests](https://en.wikipedia.org/wiki/Flesch%E2%80%93Kincaid_readability_tests) (there are two of these).
* The [Gunning fog index](https://en.wikipedia.org/wiki/Gunning_fog_index)
* The [Simple Measure of Gobbledygook grade](https://en.wikipedia.org/wiki/SMOG) (SMOG for short)
* The [Coleman-Liau index](https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index)

Some of these measures are relatively easy to compute (such as words-per-sentence, or the length of a word).  Others are more challenging.  Since this is an introductory course, you should focus on getting *as close as possible* to the actual measures you choose to compute.

For instance, computing the number of syllabus in a word is [not an easy problem](https://stackoverflow.com/questions/405161/detecting-syllables-in-a-word).  But you can come close by using a few simple rules, such as assuming that the number of syllables in a word will roughly equal the number of vowels as long as you don't count:

* double vowels (such as in r**ea**d) 
* vowels at the end of words (such as in chees**e**)

Make similar simplifying assumptions when necessary as you work to solve this problem, but be sure that you document them in your comments.


## Solution Specification
Your solution to the problem outlined above must meet the following criteria.  How you choose to meet those criteria is up to you.  Be creative!

1. You must allow the user to either give the name of a text file containing a writing sample or type it in on the console.

2. You must then display several different readability measures for the writing sample.  These measures should include (but are not limited to):  

    * The average sentence length (in words)
    * The average word length (in syllables)
    * The percent of sentences that are *long* (with a definition of what this means)
    * At least two of the readability indexes mentioned above.
    
3. Your program should provide some summative feedback on the readability of the text.  This could be an overall average, a qualitative summary (e.g. highly readable, moderately readable, or not at all readable), or even a bar graph of some sort.  Be creative!
    
4. Your program must then allow the user to save these statistics to a file and prompt them to either analyze another passage or quit.

## Assignment Specification
Since this is a project, you have a lot of freedom in how you choose to accomplish the task.  However, you are expected to make use of the following concepts somewhere in your program.

* Your program must be divided into functions which perform well-defined and logical sub-tasks for the problem.  Before you go too far on your development, check with your professor about your program structure and choice of functions.

* Your program must use both console and file input/output.

* You must validate all user input and handle any errors gracefully.

* Your program should have one global constant that serves as a flag to turn debugging messages on or off.  If the flag is set to true, then your code should print out key information about the inner workings of the program.   You should not use any other global variables. 


## Time-Saving Suggestions
This is a longer project that the first one, and will require more careful thought and planning to successfully complete.  The following suggestions will save you a lot of time.

* Make sure that each of your functions really encapsulates one particular well-defined task. If your function is more than 10-15 lines long, think carefully about if it makes sense to break it up into separate functions.  

* Use descriptive function and variable names.  For example, a function name like ``countSyllables`` is far more descriptive than ``cs`` and the same is true for variable names.  

* Before each function prototype, include a multi-line comment that explains the input and output of the function and the task that it is responsible for completing.  

* Think carefully about your code before you write it.  It is worth programming a little slower in order to make sure that the code you write is clear, simple, and easy to read and modify.  

* Start writing your functions one-by-one and test them as you write them.  Make sure that each function behaves correctly before moving on to the next function.  This will potentially save you a huge amount of time and frustration when debugging.

## Code Review and Grading
Before you can turn in your project, you must participate in a [code review](https://en.wikipedia.org/wiki/Code_review) with your instructor. This [walk-through](https://en.wikipedia.org/wiki/) style review is a guided-tour of your source code in which you describe how you implemented the various features, explain why you made the choices you did, and solicit constructive input which might help improve your final product.  

Once your final product has been turned in, it will be graded according to the accompanying code review rubric.
