<?php
/**
 * @file
 * ecoles_base.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ecoles_base_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-ecoles-menu_accueil:<front>.
  $menu_links['menu-ecoles-menu_accueil:<front>'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Accueil',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_accueil:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-ecoles-menu_ajouter-nouveau:ecoles/eleve/create.
  $menu_links['menu-ecoles-menu_ajouter-nouveau:ecoles/eleve/create'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/eleve/create',
    'router_path' => 'ecoles/eleve/create',
    'link_title' => 'Ajouter Nouveau',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_ajouter-nouveau:ecoles/eleve/create',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_lves:ecoles/eleve/list',
  );
  // Exported menu link: menu-ecoles-menu_anne-scolaire:ecoles/utile/list/taompianarana.
  $menu_links['menu-ecoles-menu_anne-scolaire:ecoles/utile/list/taompianarana'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/utile/list/taompianarana',
    'router_path' => 'ecoles/utile/list/%',
    'link_title' => 'Année scolaire',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_anne-scolaire:ecoles/utile/list/taompianarana',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_utile:ecoles/utile/list',
  );
  // Exported menu link: menu-ecoles-menu_classe:ecoles/utile/list/classe.
  $menu_links['menu-ecoles-menu_classe:ecoles/utile/list/classe'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/utile/list/classe',
    'router_path' => 'ecoles/utile/list/%',
    'link_title' => 'Classe',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_classe:ecoles/utile/list/classe',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_utile:ecoles/utile/list',
  );
  // Exported menu link: menu-ecoles-menu_configuration:ecoles/configuration.
  $menu_links['menu-ecoles-menu_configuration:ecoles/configuration'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/configuration',
    'router_path' => 'ecoles/configuration',
    'link_title' => 'Configuration',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_configuration:ecoles/configuration',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-ecoles-menu_export-vers-excel:ecoles/eleve/export.
  $menu_links['menu-ecoles-menu_export-vers-excel:ecoles/eleve/export'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/eleve/export',
    'router_path' => 'ecoles/eleve/export',
    'link_title' => 'Export vers excel',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_export-vers-excel:ecoles/eleve/export',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_exportimport:ecoles/eleve/import-export',
  );
  // Exported menu link: menu-ecoles-menu_exportimport:ecoles/eleve/import-export.
  $menu_links['menu-ecoles-menu_exportimport:ecoles/eleve/import-export'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/eleve/import-export',
    'router_path' => 'ecoles/eleve/import-export',
    'link_title' => 'Export/import',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_exportimport:ecoles/eleve/import-export',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-ecoles-menu_import-csv:ecoles/eleve/import-csv.
  $menu_links['menu-ecoles-menu_import-csv:ecoles/eleve/import-csv'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/eleve/import-csv',
    'router_path' => 'ecoles/eleve/import-csv',
    'link_title' => 'import csv',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_import-csv:ecoles/eleve/import-csv',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_exportimport:ecoles/eleve/import-export',
  );
  // Exported menu link: menu-ecoles-menu_liste-de-tous-les-lves:liste/eleves.
  $menu_links['menu-ecoles-menu_liste-de-tous-les-lves:liste/eleves'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'liste/eleves',
    'router_path' => 'liste/eleves',
    'link_title' => 'Liste de tous les élèves',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_liste-de-tous-les-lves:liste/eleves',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_lves:ecoles/eleve/list',
  );
  // Exported menu link: menu-ecoles-menu_liste-des-lves-actuel:ecoles/eleve/list.
  $menu_links['menu-ecoles-menu_liste-des-lves-actuel:ecoles/eleve/list'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/eleve/list',
    'router_path' => 'ecoles/eleve/list',
    'link_title' => 'Liste des élèves actuel',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_liste-des-lves-actuel:ecoles/eleve/list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_lves:ecoles/eleve/list',
  );
  // Exported menu link: menu-ecoles-menu_lve-no-class:ecoles/eleve-no-class/list.
  $menu_links['menu-ecoles-menu_lve-no-class:ecoles/eleve-no-class/list'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/eleve-no-class/list',
    'router_path' => 'ecoles/eleve-no-class/list',
    'link_title' => 'élève no classé',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_lve-no-class:ecoles/eleve-no-class/list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_lves:ecoles/eleve/list',
  );
  // Exported menu link: menu-ecoles-menu_lves:ecoles/eleve/list.
  $menu_links['menu-ecoles-menu_lves:ecoles/eleve/list'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/eleve/list',
    'router_path' => 'ecoles/eleve/list',
    'link_title' => 'élèves',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_lves:ecoles/eleve/list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-ecoles-menu_niveau:ecoles/utile/list/niveau.
  $menu_links['menu-ecoles-menu_niveau:ecoles/utile/list/niveau'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/utile/list/niveau',
    'router_path' => 'ecoles/utile/list/%',
    'link_title' => 'Niveau',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_niveau:ecoles/utile/list/niveau',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_utile:ecoles/utile/list',
  );
  // Exported menu link: menu-ecoles-menu_periode:ecoles/utile/list/period.
  $menu_links['menu-ecoles-menu_periode:ecoles/utile/list/period'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/utile/list/period',
    'router_path' => 'ecoles/utile/list/%',
    'link_title' => 'Periode',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_periode:ecoles/utile/list/period',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_utile:ecoles/utile/list',
  );
  // Exported menu link: menu-ecoles-menu_re-inscription-:ecoles/eleve/re-inscription.
  $menu_links['menu-ecoles-menu_re-inscription-:ecoles/eleve/re-inscription'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/eleve/re-inscription',
    'router_path' => 'ecoles/eleve/re-inscription',
    'link_title' => 'Re-inscription ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_re-inscription-:ecoles/eleve/re-inscription',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-ecoles-menu_lves:ecoles/eleve/list',
  );
  // Exported menu link: menu-ecoles-menu_utile:ecoles/utile/list.
  $menu_links['menu-ecoles-menu_utile:ecoles/utile/list'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'link_path' => 'ecoles/utile/list',
    'router_path' => 'ecoles/utile/%',
    'link_title' => 'Utile',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-ecoles-menu_utile:ecoles/utile/list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Accueil');
  t('Ajouter Nouveau');
  t('Année scolaire');
  t('Classe');
  t('Configuration');
  t('Export vers excel');
  t('Export/import');
  t('Liste de tous les élèves');
  t('Liste des élèves actuel');
  t('Niveau');
  t('Periode');
  t('Re-inscription ');
  t('Utile');
  t('import csv');
  t('élève no classé');
  t('élèves');

  return $menu_links;
}
