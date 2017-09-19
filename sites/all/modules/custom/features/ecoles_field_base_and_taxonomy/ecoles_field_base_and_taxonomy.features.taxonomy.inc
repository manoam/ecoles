<?php
/**
 * @file
 * ecoles_field_base_and_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ecoles_field_base_and_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'classe' => array(
      'name' => 'Classe',
      'machine_name' => 'classe',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'niveau' => array(
      'name' => 'Niveau',
      'machine_name' => 'niveau',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'period' => array(
      'name' => 'period',
      'machine_name' => 'period',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'sexe' => array(
      'name' => 'Sexe',
      'machine_name' => 'sexe',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Étiquettes',
      'machine_name' => 'tags',
      'description' => 'Utilisez les étiquettes pour regrouper les articles sur des sujets similaires dans des catégories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'taompianarana' => array(
      'name' => 'Taompianarana',
      'machine_name' => 'taompianarana',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
