#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Function to perform linear search for a product in the list
void linear_search_product(const char *product_list[], int list_size, const char *target_product, int *result_indices, int *result_count) {
    *result_count = 0;

    for (int i = 0; i < list_size; i++) {
        if (strcmp(product_list[i], target_product) == 0) {
            result_indices[(*result_count)++] = i;
        }
    }
}

int main() {
    const char *products[MAX_PRODUCTS] = {"Apple", "Banana", "Orange", "Apple", "Mango", "Apple"};

    const char *target_product = "Apple";
    int result_indices[MAX_PRODUCTS];
    int result_count;

    linear_search_product(products, 6, target_product, result_indices, &result_count);

    if (result_count > 0) {
        printf("The target product '%s' was found at indices: ", target_product);
        for (int i = 0; i < result_count; i++) {
            printf("%d", result_indices[i]);
            if (i < result_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("The target product '%s' was not found in the list.\n", target_product);
    }

    return 0;
}
