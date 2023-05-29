const failureTable = (pattern) =>{
    let failure = [];
    failure[0] = 0;
    failure[1] = 0;
    const patternL = pattern.length;

    for(let i=2; i<= patternL; i++){
        let j = failure[i-1];

        while(true){
            if(pattern[j] === pattern[i-1]) {
                failure[i] = j+1;
                break;
            }
            else if(j === 0){
                failure[i] = 0;
                break;
            }
           j = failure[j];
        }
    }

    return failure;
    // console.log('Failure Table:');
    // for(let i=0; i<= patternL; i++){
    //     console.log('index: ',i,' value: ',failure[i]);
    // }

}

const kmp = (string,pattern) =>{
    const strL = string.length;
    const patL = pattern.length;
    let patIndx = 0;
    const failure = failureTable(pattern);
    //console.log(failure);

    for(let i=0; i<strL; i++){
        //console.log("str: ",string[i],' pat: ',pattern[patIndx]);
        if(string[i] === pattern[patIndx]){
            if(patIndx === patL-1) return i - patIndx;
            else patIndx += 1;
        }else{
            if(patIndx === 0) continue;
            else{
                 patIndx = failure[patIndx];
                 i = i - 1;
            }
        }
    }
    return -1;
}


// const result = kmp('towhidul islam','is');
// console.log('pattern starting index ',result);

const string = ['ababcaabadaaababxac', 'towhidul islam','ababac','aabbaacbad']
const pattern = ['babxa','ul','ba','acbae'];

for(let i=0; i<string.length; i++){
    const result = kmp(string[i],pattern[i]);
    if( result !== -1 ) console.log('pattern: ','"'+pattern[i]+'"',' found in string: ','"'+string[i]+'"', 'at index: ', result);
    else console.log('pattern: ','"'+pattern[i]+'"','not found in string: "','"'+string[i]+'"');
}