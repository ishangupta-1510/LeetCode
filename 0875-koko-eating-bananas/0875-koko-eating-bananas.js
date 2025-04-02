/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */

 function canEat(banana, piles, allowedHours){
        let hours = 0;
        for(let i=0;i<piles.length;i++){
            hours += Math.ceil(piles[i]/banana);
        }
        console.log(banana, allowedHours, hours);
        return allowedHours >= hours;
    }
var minEatingSpeed = function(piles, h) {
    let start = 0, end = Math.max(...piles);
    while(start <= end){
        let mid = start + Math.floor((end-start)/2);
        if(canEat(mid, piles, h)){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return start;
};