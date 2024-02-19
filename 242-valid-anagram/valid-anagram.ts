function isAnagram(s: string, t: string): boolean {
    const map = new Map();
    if(s.length !== t.length ){
        return false;
    }
    for(let st of s){
        if(map.get(st) === undefined){
            map.set(st, 1);
        }
        else{
            map.set(st, map.get(st) + 1);
        }
    }
    for(let st of t){
        if(map.get(st) === undefined){
            return false;
        }
        if(map.get(st) <= 0){
            return false;
        }
        else{
           map.set(st, map.get(st) - 1);
        }
    }
    return true;
};