function sortLibrary() {
    var keepSorting = true;
    var temp;
    while(keepSorting){
        keepSorting = false;
        for (let i =0; i<library.length - 1; i++){
             if (library[i].title < library[i+1].title){
                 temp = library[i+1];
                 library[i+1] = library[i];
                 library[i] = temp;
                 keepSorting = true;
             }
        }
    }
    console.log(library);
    // var library is defined, use it in your code
    // use console.log(library) to output the sorted library data
}

// tail starts here
var library = [
    {
        author: 'Bill Gates',
        title: 'The Road Ahead',
        libraryID: 1254
    },
    {
        author: 'Steve Jobs',
        title: 'Walter Isaacson',
        libraryID: 4264
    },
    {
        author: 'Suzanne Collins',
        title: 'Mockingjay: The Final Book of The Hunger Games',
        libraryID: 3245
    }
];

sortLibrary();