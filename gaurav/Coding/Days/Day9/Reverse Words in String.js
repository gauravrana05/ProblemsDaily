/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {

    let x = s.replace(/[^A-Za-z0-9]+/g, " ");
    let w = x.trim().split(" ");
    
    var ans = "";
    for( let word of w){
           ans = word + " " + ans
    }

    return ans.trim(); 

};