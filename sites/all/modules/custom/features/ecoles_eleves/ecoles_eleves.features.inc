<?php
/**
 * @file
 * ecoles_eleves.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ecoles_eleves_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function ecoles_eleves_eck_bundle_info() {
  $items = array(
    'eleve_eleve' => array(
      'machine_name' => 'eleve_eleve',
      'entity_type' => 'eleve',
      'name' => 'eleve',
      'label' => 'eleve',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function ecoles_eleves_eck_entity_type_info() {
  $items = array(
    'eleve' => array(
      'name' => 'eleve',
      'label' => 'eleve',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'uuid' => array(
          'label' => 'UUID',
          'type' => 'text',
          'behavior' => 'uuid',
        ),
      ),
    ),
  );
  return $items;
}
