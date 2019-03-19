//
// Created by emanuel on 12/4/2018.
//

#include "qxdsearching.h"


bool qx_contains(int array[], size_t num_elems, int element, qxSortType sorting){

    if(sorting == 0){
        int i = 0;

        for(i = 0; i < num_elems ;i++){
            if(array[i] == element) return true;
        }

        return false;

    }else if(sorting == 1){

        int in = 0, end = num_elems;

        while(in <= end){

            int mid = (in+end) / 2;

            if(element == array[mid]) return true;

            if(element < array[mid]) end = mid + 1;

            else in = mid + 1;
        }

        return false;

    }else{

        int in = 0, end = num_elems;

        while(in <= end){

            int mid = (in+end) / 2;

            if(element == array[mid]) return true;

            if(element > array[mid]) end = mid + 1;

            else in = mid + 1;
        }

        return false;
    }

}

qxIndex qx_find_index(int array[], size_t num_elems, int element, qxSortType sorting){

    if(sorting == 0){
        int i = 0;

        for(i = 0; i < num_elems ;i++){
            if(array[i] == element) return (size_t)i;
        }

        return QX_LAMBDA_INDEX;

    }else if(sorting == 1){

        int in = 0, end = num_elems;

        while(in <= end){

            int mid = (in+end) / 2;

            if(element == array[mid]) return (size_t)mid;

            if(element < array[mid]) end = mid + 1;

            else in = mid + 1;
        }

        return QX_LAMBDA_INDEX;

    }else{

        int in = 0, end = num_elems;

        while(in <= end){

            int mid = (in+end) / 2;

            if(element == array[mid]) return (size_t)mid;

            if(element > array[mid]) end = mid + 1;

            else in = mid + 1;
        }

        return QX_LAMBDA_INDEX;
    }

}

qxIndex qx_lower_bound(int array[], size_t num_elems, int element, qxSortType sorting){

    if(sorting == 0){
        int i = 0;

        for(i = 0; i < num_elems ;i++){
            if(array[i] == element) return (size_t)i;
        }

        return QX_LAMBDA_INDEX;

    }else if(sorting == 1){

        int in = 0, end = num_elems;
        int mid = 0;
        bool exist = false;

        while(in <= end){

            mid = (in+end) / 2;

            if(element == array[mid]) exist = true;

            if(element < array[mid]) end = mid + 1;

            else in = mid + 1;
        }
        if(exist){
            while(mid >=0 && array[mid] == element){
                mid--;
            }

            return (size_t)mid;
        }

        return QX_LAMBDA_INDEX;

    }else{

        int in = 0, end = num_elems;
        bool exist = false;

        int mid = 0;

        while(in <= end){

            mid = (in+end) / 2;

            if(element == array[mid]) exist = true;

            if(element > array[mid]) end = mid + 1;

            else in = mid + 1;
        }

        if(exist){
            while(mid >=0 && array[mid] == element){
                mid--;
            }

            return (size_t)mid;
        }

        return QX_LAMBDA_INDEX;
    }


}

qxIndex qx_upper_bound(int array[], size_t num_elems, int element, qxSortType sorting){

    if(sorting == 0){
        int i = 0;
        bool exist = false;

        for(i = 0; i < num_elems ;i++){
            if(array[i] == element){
                exist = true;
                break;
            }
        }

        if(exist){

            while (i <= num_elems && array[i] == element) {
                i++;
            }

            return i;
        }

        return QX_LAMBDA_INDEX;

    }else if(sorting == 1){

        int in = 0, end = num_elems;
        int mid = 0;
        bool exist = false;

        while(in <= end){

            mid = (in+end) / 2;

            if(element == array[mid]) exist = true;

            if(element < array[mid]) end = mid + 1;

            else in = mid + 1;
        }
        if(exist){
            while(mid <= num_elems && array[mid] == element){
                mid++;
            }

            return (size_t)mid;
        }

        return QX_LAMBDA_INDEX;

    }else{

        int in = 0, end = num_elems;
        bool exist = false;

        int mid = 0;

        while(in <= end){

            mid = (in+end) / 2;

            if(element == array[mid]) exist = true;

            if(element > array[mid]) end = mid + 1;

            else in = mid + 1;
        }

        if(exist){
            while(mid <= num_elems && array[mid] == element){
                mid++;
            }

            return (size_t)mid;
        }

        return QX_LAMBDA_INDEX;
    }


}